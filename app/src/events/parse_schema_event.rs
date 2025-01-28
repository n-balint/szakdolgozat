use std::{
    fs::File, io::Read, path::PathBuf, sync::atomic::Ordering, thread::sleep, time::Duration,
};

use log::{debug, error};
use tree_sitter_cql::language;

use crate::{
    cassandra::ast_queries::parse_database, postgres::ast_queries::parse_postgres_dump,
    ui::MigrateAppState,
};

use super::Event;

pub struct ParseSchemaEvent {
    file_path: PathBuf,
    app_state: MigrateAppState,
}

impl ParseSchemaEvent {
    pub fn new(file_path: PathBuf, app_state: MigrateAppState) -> Self {
        Self {
            file_path,
            app_state,
        }
    }
}

impl Event for ParseSchemaEvent {
    type AppState = MigrateAppState;
    fn handle(
        &mut self,
        processing: &std::sync::Arc<std::sync::atomic::AtomicBool>,
    ) -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
        processing.store(true, Ordering::SeqCst);

        debug!("Opening file: {:#?}", self.file_path);
        let mut f = File::open(
            self.app_state
                .postgres_dump
                .as_ref()
                .expect("postgres dump path was not available but it should be."),
        )?;

        debug!("Successfully opened file: {:#?}", f);
        let mut buf = String::new();
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        debug!("Created postgres parser");
        f.read_to_string(&mut buf)?;
        debug!("Read postgres dump to buf.");

        debug!("Parsing dump.");
        let root = parser.parse(&buf, None).unwrap();
        debug!("Finished parsing dump.");
        debug!("Converting AST to schema.");
        let parsed_schema = parse_postgres_dump(&buf, &root.root_node());
        match parsed_schema {
            Ok(schema) => {
                self.app_state.schema = Some(schema);
            }
            Err(e) => println!("ERRRRR: {}", e),
        }
        Ok(())
    }

    fn app_state(&self) -> Self::AppState {
        self.app_state.clone()
    }
}
