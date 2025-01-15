use std::{
    error::Error,
    sync::{
        atomic::AtomicBool,
        mpsc::{Receiver, Sender},
    },
};

pub trait Event {
    type AppState;
    fn handle(&mut self) -> Result<(), Box<dyn Error + Send + Sync>>;
    fn app_state(&self) -> Self::AppState;
}

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
pub struct MigrateAppState {}

impl MigrateAppState {
    fn new() -> Self {
        Self {}
    }
}

#[derive(Debug)]
pub struct App {
    app_state: MigrateAppState,
    worker_tx: Sender<Box<dyn Event<AppState = MigrateAppState> + Send>>,
    event_rx: Receiver<Box<dyn Event<AppState = MigrateAppState> + Send>>,
    error_rx: Receiver<Box<dyn Error + Send + Sync>>,
    latest_error: Option<Box<dyn Error + Send + Sync>>,
    is_processing_event: AtomicBool,
}

impl App {
    fn new(
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
            is_processing_event: AtomicBool::new(false),
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
