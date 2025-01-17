use std::{
    fs::File, io::Read, path::PathBuf, sync::atomic::Ordering, thread::sleep, time::Duration,
};

use log::{debug, error};
use tree_sitter_cql::language;

use crate::{cassandra::ast_queries::parse_database, ui::MigrateAppState};

use super::Event;

pub struct ParseKeyspaceEvent {
    file_path: PathBuf,
    app_state: MigrateAppState,
}

impl ParseKeyspaceEvent {
    pub fn new(file_path: PathBuf, app_state: MigrateAppState) -> Self {
        Self {
            file_path,
            app_state,
        }
    }
}

impl Event for ParseKeyspaceEvent {
    type AppState = MigrateAppState;
    fn handle(
        &mut self,
        processing: &std::sync::Arc<std::sync::atomic::AtomicBool>,
    ) -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
        processing.store(true, Ordering::SeqCst);

        debug!("Opening file: {:#?}", self.file_path);
        let mut f = File::open(
            self.app_state
                .cassandra_dump
                .as_ref()
                .expect("cassandra dump path was not available but it should be."),
        )?;

        debug!("Successfully opened file: {:#?}", f);
        let mut buf = String::new();
        let mut parser = tree_sitter::Parser::new();
        parser.set_language(&tree_sitter_cql::language()).unwrap();
        debug!("Created cql parser");
        f.read_to_string(&mut buf)?;
        debug!("Read cql dump to buf.");

        debug!("Parsing dump.");
        let root = parser.parse(&buf, None).unwrap();
        debug!("Finished parsing dump.");
        debug!("Converting AST to keyspace.");
        let parsed_keyspace = parse_database(&buf, &root)
            .expect("IMPLEMENT PROPER ERROR HANDLING FOR PARSING FUNCTIONS.");
        self.app_state.keyspace = Some(parsed_keyspace);
        Ok(())
    }

    fn app_state(&self) -> Self::AppState {
        self.app_state.clone()
    }
}
