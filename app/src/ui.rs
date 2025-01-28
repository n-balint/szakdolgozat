use std::{
    borrow::BorrowMut,
    error::Error,
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

use crate::{
    cassandra::database::Keyspace,
    events::{parse_schema_event::ParseSchemaEvent, Event},
    postgres::conversion::KeyspaceConverter,
};
use crate::{events::parse_keyspace_event::ParseKeyspaceEvent, postgres::database::Schema};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum PostgresConversionState {
    Start,
    SelectKeyspaceDump,
    SelectDumpFolder,
    ExtractRelations,
    SelectCorrectRelations,
    ExtractFunctionalDependencies,
    SelectCorrectDependencies,
    SelectNormalizationLevel,
    MigrateToPostgres,
}

impl PostgresConversionState {
    fn next(self) -> Self {
        match self {
            Self::Start => Self::SelectKeyspaceDump,
            Self::SelectKeyspaceDump => Self::SelectDumpFolder,
            Self::SelectDumpFolder => Self::ExtractRelations,
            Self::ExtractRelations => Self::SelectCorrectRelations,
            Self::SelectCorrectRelations => Self::ExtractFunctionalDependencies,
            Self::ExtractFunctionalDependencies => Self::SelectCorrectDependencies,
            Self::SelectCorrectDependencies => Self::SelectNormalizationLevel,
            Self::SelectNormalizationLevel => Self::MigrateToPostgres,
            Self::MigrateToPostgres => panic!("called next on the final state."),
        }
    }

    fn prev(self) -> Self {
        match self {
            Self::Start => panic!("called prev on the first state."),
            Self::SelectKeyspaceDump => Self::Start,
            Self::SelectDumpFolder => Self::SelectKeyspaceDump,
            Self::ExtractRelations => Self::SelectDumpFolder,
            Self::SelectCorrectRelations => Self::ExtractRelations,
            Self::ExtractFunctionalDependencies => Self::SelectCorrectRelations,
            Self::SelectCorrectDependencies => Self::ExtractFunctionalDependencies,
            Self::SelectNormalizationLevel => Self::SelectCorrectDependencies,
            Self::MigrateToPostgres => Self::SelectNormalizationLevel,
        }
    }

    fn is_first(self) -> bool {
        self == Self::Start
    }
    fn is_final(self) -> bool {
        self == Self::MigrateToPostgres
    }
}

impl CassandraConversionState {
    fn next(self) -> Self {
        match self {
            Self::Start => Self::SelectSchemaDump,
            Self::SelectSchemaDump => Self::SelectDuplicatingColumns,
            Self::SelectDuplicatingColumns => Self::MigrateToCassandra,
            Self::MigrateToCassandra => panic!("called next on the final state."),
        }
    }

    fn prev(self) -> Self {
        match self {
            CassandraConversionState::Start => panic!("called prev on the first state."),
            CassandraConversionState::SelectSchemaDump => Self::Start,
            CassandraConversionState::SelectDuplicatingColumns => Self::SelectSchemaDump,
            CassandraConversionState::MigrateToCassandra => Self::SelectDuplicatingColumns,
        }
    }

    fn is_first(self) -> bool {
        self == Self::Start
    }

    fn is_final(self) -> bool {
        self == Self::MigrateToCassandra
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum NormalizationLevel {
    NF1,
    NF2,
    NF3,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CassandraConversionState {
    Start,
    SelectSchemaDump,
    SelectDuplicatingColumns,
    MigrateToCassandra,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ConversionDirection {
    CassandraToPostgres(PostgresConversionState),
    PostgresToCassandra(CassandraConversionState),
}

#[derive(Debug, Clone)]
pub struct MigrateAppState {
    pub keyspace: Option<Keyspace>,
    pub cassandra_dump: Option<PathBuf>,
    pub cassandra_data_dump: Option<PathBuf>,
    pub schema: Option<Schema>,
    pub postgres_dump: Option<PathBuf>,
    pub keyspace_converter: Option<KeyspaceConverter>,
}

impl MigrateAppState {
    fn new() -> Self {
        Self {
            keyspace: None,
            schema: None,
            cassandra_dump: None,
            cassandra_data_dump: None,
            postgres_dump: None,
            keyspace_converter: None,
        }
    }
}

#[derive(Debug)]
pub struct App {
    conversion_direction: Option<ConversionDirection>,
    app_state: MigrateAppState,
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
            self.app_state = event.app_state();
        }
        while let Ok(e) = self.error_rx.try_recv() {
            self.latest_error = Some(e);
        }
    }
}

impl eframe::App for App {
    fn update(&mut self, ctx: &egui::Context, frame: &mut eframe::Frame) {
        self.handle_gui_events();
        ctx.request_repaint();
        CentralPanel::default().show(ctx, |ui| {
            if self.is_processing_event.load(Ordering::SeqCst) {
                ui.disable();
            }
            if ui.button("reset").clicked() {
                self.app_state = MigrateAppState::new();
                self.conversion_direction = None;
            }
            if ui.button("state").clicked() {
                println!("{:#?}", self);
            }
            match self.conversion_direction {
                Some(conversion_direction) => match conversion_direction {
                    ConversionDirection::CassandraToPostgres(state) => {
                        self.handle_cassandra_to_postgres(state, ui);
                    }
                    ConversionDirection::PostgresToCassandra(state) => {
                        self.handle_postgres_to_cassandra(state, ui);
                    }
                },
                None => {
                    self.select_conversion_direction(ui);
                }
            }
        });
    }
}

impl App {
    fn handle_cassandra_to_postgres(&mut self, state: PostgresConversionState, ui: &mut Ui) {
        match state {
            PostgresConversionState::Start => {
                self.conversion_direction =
                    Some(ConversionDirection::CassandraToPostgres(state.next()))
            }
            PostgresConversionState::SelectKeyspaceDump => {
                ui.label("Select keyspace dump:");
                if ui.button("Open file").clicked() {
                    let picker = FileDialog::new()
                        .add_filter("CQL dump", &["cql"])
                        .pick_file();
                    debug!("Created file picker.");
                    if let Some(path) = picker {
                        self.app_state.cassandra_dump = Some(path);
                        debug!("Got path: {:#?}", self.app_state.cassandra_dump);
                        let parse_event = ParseKeyspaceEvent::new(
                            self.app_state.cassandra_dump.clone().expect("Impossible."),
                            self.app_state.clone(),
                        );
                        self.worker_tx.send(Box::new(parse_event)).unwrap();
                        self.conversion_direction =
                            Some(ConversionDirection::CassandraToPostgres(state.next()));
                        debug!("Switching to next state.");
                    }
                }
            }
            PostgresConversionState::SelectDumpFolder => {
                ui.label("Select dump folder:");
                if ui.button("Open folder").clicked() {
                    let folder_picker = FileDialog::new().pick_folder();
                    if let Some(path) = folder_picker {
                        self.app_state.cassandra_data_dump = Some(path);
                        self.conversion_direction =
                            Some(ConversionDirection::CassandraToPostgres(state.next()))
                    }
                }
            }
            PostgresConversionState::ExtractRelations => {}
            PostgresConversionState::SelectCorrectRelations => {}
            PostgresConversionState::ExtractFunctionalDependencies => {}
            PostgresConversionState::SelectCorrectDependencies => {}
            PostgresConversionState::SelectNormalizationLevel => {}
            PostgresConversionState::MigrateToPostgres => {}
        }
    }

    fn handle_postgres_to_cassandra(&mut self, state: CassandraConversionState, ui: &mut Ui) {
        match state {
            CassandraConversionState::Start => {
                self.conversion_direction = Some(ConversionDirection::PostgresToCassandra(
                    CassandraConversionState::SelectSchemaDump,
                ));
            }
            CassandraConversionState::SelectSchemaDump => {
                ui.label("Select schema dump:");
                if ui.button("Open file").clicked() {
                    let picker = FileDialog::new()
                        .add_filter("SQL dump", &["sql"])
                        .pick_file();
                    if let Some(path) = picker {
                        self.app_state.postgres_dump = Some(path);
                        debug!("Got path: {:#?}", self.app_state.cassandra_dump);
                        let parse_event = ParseSchemaEvent::new(
                            self.app_state.postgres_dump.clone().expect("Impossible."),
                            self.app_state.clone(),
                        );
                        self.worker_tx.send(Box::new(parse_event)).unwrap();
                        self.conversion_direction =
                            Some(ConversionDirection::PostgresToCassandra(state.next()));
                    }
                }
            }
            CassandraConversionState::SelectDuplicatingColumns => {}
            CassandraConversionState::MigrateToCassandra => todo!(),
        }
    }

    fn select_conversion_direction(&mut self, ui: &mut Ui) {
        ui.label(String::from("Select conversion direction:"));
        ComboBox::from_label("").show_ui(ui, |ui| {
            ui.selectable_value(
                &mut self.conversion_direction,
                Some(ConversionDirection::CassandraToPostgres(
                    PostgresConversionState::Start,
                )),
                "Cassandra -> Postgres",
            );
            ui.selectable_value(
                &mut self.conversion_direction,
                Some(ConversionDirection::PostgresToCassandra(
                    CassandraConversionState::Start,
                )),
                "Postgres -> Cassandra",
            );
        });
    }
}
