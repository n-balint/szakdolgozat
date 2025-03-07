use std::{
    fs::{File, OpenOptions},
    io::{Read, Write},
    path::PathBuf,
    sync::atomic::Ordering,
};

use tree_sitter::Parser;

use crate::{
    cassandra::{
        ast_queries::parse_database,
        database::Keyspace,
        migration::{conversion::convert_keyspace_to_schema, schema_ir::generate_schema_ir},
    },
    fd::DependencyInference,
    query::Query,
    ui::{MigrateAppState, NormalizationLevel},
};

use super::Event;

pub(crate) struct CassandraPostgresMigrationEvent {
    app_state: MigrateAppState,
    keyspace_dump_path: PathBuf,
    export_folder_path: PathBuf,
    data_folder_path: PathBuf,
    normalization_level: NormalizationLevel,
}

impl CassandraPostgresMigrationEvent {
    pub(crate) fn new(
        keyspace_dump_path: PathBuf,
        export_folder_path: PathBuf,
        data_folder_path: PathBuf,
        normalization_level: NormalizationLevel,
    ) -> Self {
        Self {
            app_state: MigrateAppState::new(),
            keyspace_dump_path,
            export_folder_path,
            data_folder_path,
            normalization_level,
        }
    }
}

impl Event for CassandraPostgresMigrationEvent {
    type AppState = MigrateAppState;

    fn handle(
        &mut self,
        processing: &std::sync::Arc<std::sync::atomic::AtomicBool>,
    ) -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
        processing.store(true, Ordering::SeqCst);
        let mut keyspace_file = File::open(&self.keyspace_dump_path)?;
        let mut buf = String::new();
        let mut parser = Parser::new();
        parser.set_language(&tree_sitter_cql::language()).unwrap();
        keyspace_file.read_to_string(&mut buf)?;
        let root = parser.parse(&buf, None).unwrap();
        let keyspace = parse_database(&buf, &root).expect("TODO: Fix result types");
        let converted_schema =
            convert_keyspace_to_schema(&keyspace).expect("TODO: Fix result types");
        generate_schema_ir(&keyspace, &converted_schema, &self.data_folder_path)
            .expect("TODO: Fix result types");

        let mut dependency_inference =
            DependencyInference::new(converted_schema, self.data_folder_path.clone());
        dependency_inference.extract_dependencies();
        dependency_inference.verify_and_set_primary_keys();
        match &self.normalization_level {
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

        let query_string_file = self.export_folder_path.join("dump.sql");
        let mut file = OpenOptions::new()
            .write(true)
            .create(true)
            .truncate(true)
            .open(query_string_file)?;
        println!("da string: {}", query_string);
        file.write_all(query_string.as_bytes())?;

        Ok(())
    }

    fn app_state(&self) -> Self::AppState {
        self.app_state.clone()
    }
}
