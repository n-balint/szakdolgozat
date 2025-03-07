use std::{
    borrow::BorrowMut,
    error::Error,
    fs::{File, OpenOptions},
    io::{Read, Write},
    path::PathBuf,
    sync::{
        atomic::{AtomicBool, Ordering},
        mpsc::{Receiver, Sender},
        Arc,
    },
    thread::sleep,
    time::Duration,
};

use egui::{CentralPanel, ComboBox, Ui};
use log::debug;
use rfd::FileDialog;
use tree_sitter::Parser;

use crate::{
    cassandra::{
        ast_queries::parse_database,
        database::Keyspace,
        migration::{
            conversion::{convert_ir_to_final_export, convert_keyspace_to_schema},
            schema_ir::generate_schema_ir,
        },
    },
    events::Event,
    fd::DependencyInference,
    postgres::{ast_queries::parse_postgres_dump, conversion::simple_conversion::SimpleConversion},
    query::Query,
};
use crate::{
    events::cassandra_postgres_migration::CassandraPostgresMigrationEvent,
    postgres::database::Schema,
};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum PostgresConversionState {
    Start,
    ConversionTasks,
    Finished,
}

impl PostgresConversionState {
    fn next(self) -> Self {
        match self {
            Self::Start => Self::ConversionTasks,
            Self::ConversionTasks => Self::Finished,
            Self::Finished => panic!("called next on the final state."),
        }
    }

    fn prev(self) -> Self {
        match self {
            Self::Start => panic!("called prev on the first state."),
            Self::ConversionTasks => Self::Start,
            Self::Finished => Self::ConversionTasks,
        }
    }

    fn is_first(self) -> bool {
        self == Self::Start
    }
    fn is_final(self) -> bool {
        self == Self::Finished
    }
}

impl CassandraConversionState {
    fn next(self) -> Self {
        match self {
            Self::Start => Self::ConversionTasks,
            Self::ConversionTasks => Self::Finished,
            Self::Finished => panic!("called next on the final state."),
        }
    }

    fn prev(self) -> Self {
        match self {
            Self::Start => panic!("called prev on the first state."),
            Self::ConversionTasks => Self::Start,
            Self::Finished => Self::ConversionTasks,
        }
    }

    fn is_first(self) -> bool {
        self == Self::Start
    }
    fn is_final(self) -> bool {
        self == Self::Finished
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum NormalizationLevel {
    NF1,
    NF2,
    NF3,
}

impl std::fmt::Display for NormalizationLevel {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            NormalizationLevel::NF1 => write!(f, "1NF"),
            NormalizationLevel::NF2 => write!(f, "2NF"),
            NormalizationLevel::NF3 => write!(f, "3NF"),
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CassandraConversionState {
    Start,
    ConversionTasks,
    Finished,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ConversionDirection {
    CassandraToPostgres(CassandraConversionState),
    PostgresToCassandra(PostgresConversionState),
}

#[derive(Debug, Clone)]
pub struct MigrateAppState {
    keyspace: Option<Keyspace>,
    dump_file_path: Option<PathBuf>,
    data_dump_folder: Option<PathBuf>,
    converted_folder: Option<PathBuf>,
    normalization_level: NormalizationLevel,
    schema: Option<Schema>,
}

impl MigrateAppState {
    pub(crate) fn new() -> Self {
        Self {
            keyspace: None,
            dump_file_path: None,
            data_dump_folder: None,
            converted_folder: None,
            normalization_level: NormalizationLevel::NF1,
            schema: None,
        }
    }
}

#[derive(Debug)]
pub struct App {
    conversion_direction: Option<ConversionDirection>,
    app_state: MigrateAppState,
    previous_state: MigrateAppState,
    worker_tx: Sender<Box<dyn Event<AppState = MigrateAppState> + Send>>,
    event_rx: Receiver<Box<dyn Event<AppState = MigrateAppState> + Send>>,
    error_rx: Receiver<Box<dyn Error + Send + Sync>>,
    latest_error: Option<Box<dyn Error + Send + Sync>>,
    pub is_processing_event: Arc<AtomicBool>,
}

impl App {
    pub fn new(
        worker_tx: Sender<Box<dyn Event<AppState = MigrateAppState> + Send>>,
        event_rx: Receiver<Box<dyn Event<AppState = MigrateAppState> + Send>>,
        error_rx: Receiver<Box<dyn Error + Send + Sync>>,
    ) -> Self {
        Self {
            app_state: MigrateAppState::new(),
            previous_state: MigrateAppState::new(),
            worker_tx,
            event_rx,
            error_rx,
            latest_error: None,
            is_processing_event: Arc::new(AtomicBool::new(false)),
            conversion_direction: None,
        }
    }

    fn handle_gui_events(&mut self) {
        while let Ok(ref event) = self.event_rx.try_recv() {
            //self.app_state = event.app_state();
        }
        while let Ok(e) = self.error_rx.try_recv() {
            self.latest_error = Some(e);
        }
    }
}

impl eframe::App for App {
    fn update(&mut self, ctx: &egui::Context, frame: &mut eframe::Frame) {
        self.handle_gui_events();
        CentralPanel::default().show(ctx, |ui| {
            if self.is_processing_event.load(Ordering::SeqCst) {
                ui.disable();
            }
            let conversion_direction = self.conversion_direction.take();
            if let Some(mut conversion) = conversion_direction {
                match &mut conversion {
                    ConversionDirection::CassandraToPostgres(state) => {
                        self.handle_cassandra_to_postgres(state, ui);
                    }
                    ConversionDirection::PostgresToCassandra(state) => {
                        self.handle_postgres_to_cassandra(state, ui);
                    }
                }
                self.conversion_direction = Some(conversion);
            } else {
                self.select_conversion_direction(ui);
            }
        });
    }
}

impl App {
    fn handle_cassandra_to_postgres(&mut self, state: &mut CassandraConversionState, ui: &mut Ui) {
        match state {
            CassandraConversionState::Start => {
                if ui
                    .button("Válassza ki a keyspace struktúráját leíró filet!")
                    .clicked()
                {
                    let keyspace_file = FileDialog::new()
                        .add_filter("CQL file", &["cql"])
                        .pick_file();
                    self.app_state.dump_file_path = keyspace_file;
                }
                if ui
                    .button("Válassza ki a mappát ahol az adatbázis dump található!")
                    .clicked()
                {
                    let db_dump_folder = FileDialog::new().pick_folder();
                    self.app_state.data_dump_folder = db_dump_folder;
                }
                if ui
                    .button("Válassza ki a mappát amibe a konvertált adatok kerülnek!")
                    .clicked()
                {
                    let converted_folder = FileDialog::new().pick_folder();
                    self.app_state.converted_folder = converted_folder;
                }
                ui.label("Válassza ki a normalizálás szintjét:");
                ComboBox::from_label("")
                    .selected_text(format!("{}", self.app_state.normalization_level))
                    .show_ui(ui, |ui| {
                        ui.selectable_value(
                            &mut self.app_state.normalization_level,
                            NormalizationLevel::NF1,
                            "1NF",
                        );
                        ui.selectable_value(
                            &mut self.app_state.normalization_level,
                            NormalizationLevel::NF2,
                            "2NF",
                        );
                        ui.selectable_value(
                            &mut self.app_state.normalization_level,
                            NormalizationLevel::NF3,
                            "3NF",
                        );
                    });
                if self.app_state.converted_folder.is_some()
                    && self.app_state.data_dump_folder.is_some()
                    && self.app_state.dump_file_path.is_some()
                    && ui.button("Következő").clicked()
                {
                    *state = state.next();
                }
            }
            CassandraConversionState::ConversionTasks => {
                let mut keyspace_file =
                    File::open(self.app_state.dump_file_path.as_ref().unwrap()).unwrap();
                let mut buf = String::new();
                let mut parser = Parser::new();
                parser.set_language(&tree_sitter_cql::language()).unwrap();
                keyspace_file.read_to_string(&mut buf).unwrap();
                let root = parser.parse(&buf, None).unwrap();
                let keyspace = parse_database(&buf, &root).expect("TODO: Fix result types");
                let mut converted_schema =
                    convert_keyspace_to_schema(&keyspace).expect("TODO: Fix result types");
                generate_schema_ir(
                    &keyspace,
                    &converted_schema,
                    self.app_state.data_dump_folder.as_ref().unwrap(),
                )
                .expect("TODO: Fix result types");
                converted_schema.rotate_uuids();

                let before_normalization = converted_schema.clone();

                let mut dependency_inference = DependencyInference::new(
                    converted_schema,
                    self.app_state.data_dump_folder.clone().unwrap(),
                );
                dependency_inference.extract_dependencies();
                dependency_inference.verify_and_set_primary_keys();
                match &self.app_state.normalization_level {
                    NormalizationLevel::NF1 => {}
                    NormalizationLevel::NF2 => {
                        dependency_inference.convert_to_2nf();
                    }
                    NormalizationLevel::NF3 => {
                        dependency_inference.convert_to_2nf();
                        dependency_inference.convert_to_3nf();
                    }
                }
                dependency_inference.verify_and_set_primary_keys();
                let finalized_schema = dependency_inference.move_schema();
                let query_string = finalized_schema.to_query_string();

                let query_string_file = self
                    .app_state
                    .converted_folder
                    .as_ref()
                    .unwrap()
                    .join("dump.sql");
                let mut file = OpenOptions::new()
                    .write(true)
                    .create(true)
                    .truncate(true)
                    .open(query_string_file)
                    .unwrap();
                file.write_all(query_string.as_bytes()).unwrap();

                convert_ir_to_final_export(
                    &before_normalization,
                    &finalized_schema,
                    self.app_state.data_dump_folder.as_ref().unwrap(),
                    self.app_state.converted_folder.as_ref().unwrap(),
                )
                .expect("DO PROPER ERROR HANDLING");
                *state = state.next();
            }
            CassandraConversionState::Finished => {
                ui.label("Konverzió befejezve.");
            }
        }
    }

    fn handle_postgres_to_cassandra(&mut self, state: &mut PostgresConversionState, ui: &mut Ui) {
        match state {
            PostgresConversionState::Start => {
                if ui
                    .button("Válassza ki a séma struktúráját leíró filet!")
                    .clicked()
                {
                    let schema_file = FileDialog::new()
                        .add_filter("SQL file", &["sql"])
                        .pick_file();
                    self.app_state.dump_file_path = schema_file;
                }
                if ui
                    .button("Válassza ki a mappát ahol az adatbázis dump található!")
                    .clicked()
                {
                    let db_dump_folder = FileDialog::new().pick_folder();
                    self.app_state.data_dump_folder = db_dump_folder;
                }
                if ui
                    .button("Válassza ki a mappát amibe a konvertált adatok kerülnek!")
                    .clicked()
                {
                    let converted_folder = FileDialog::new().pick_folder();
                    self.app_state.converted_folder = converted_folder;
                }

                if self.app_state.converted_folder.is_some()
                    && self.app_state.data_dump_folder.is_some()
                    && self.app_state.dump_file_path.is_some()
                    && ui.button("Következő").clicked()
                {
                    *state = state.next();
                }
            }
            PostgresConversionState::ConversionTasks => {
                let mut schema_file =
                    File::open(self.app_state.dump_file_path.as_ref().unwrap()).unwrap();
                let mut buf = String::new();
                let mut parser = Parser::new();
                parser
                    .set_language(&tree_sitter_sequel::language())
                    .unwrap();
                schema_file.read_to_string(&mut buf).unwrap();
                let root = parser.parse(&buf, None).unwrap();
                let schema = parse_postgres_dump(&buf, &root.root_node()).unwrap();
                let query_string =
                    SimpleConversion::convert_schema_to_keyspace(&schema).to_query_string();
                let query_string_file = self
                    .app_state
                    .converted_folder
                    .as_ref()
                    .unwrap()
                    .join("dump.cql");
                let mut file = OpenOptions::new()
                    .write(true)
                    .create(true)
                    .truncate(true)
                    .open(query_string_file)
                    .unwrap();
                file.write_all(query_string.as_bytes()).unwrap();
                *state = state.next();
            }
            PostgresConversionState::Finished => {
                ui.label("Konverzió befejezve.");
            }
        }
    }

    fn select_conversion_direction(&mut self, ui: &mut Ui) {
        ui.label(String::from("Válassza ki a konverzió irányát:"));
        ComboBox::from_label("").show_ui(ui, |ui| {
            ui.selectable_value(
                &mut self.conversion_direction,
                Some(ConversionDirection::PostgresToCassandra(
                    PostgresConversionState::Start,
                )),
                "PostgreSQL -> Apache Cassandra",
            );
            ui.selectable_value(
                &mut self.conversion_direction,
                Some(ConversionDirection::CassandraToPostgres(
                    CassandraConversionState::Start,
                )),
                "Apache Cassandra -> PostgreSQL",
            );
        });
    }
}
