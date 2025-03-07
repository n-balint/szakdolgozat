use std::{collections::HashMap, error::Error, fs::File, io::Write, path::PathBuf};

use csv::{ReaderBuilder, StringRecord, WriterBuilder};

use crate::{
    cassandra::database::{
        ColumnDefinition as CassandraColumnDefinition, Keyspace, Replication, Strategy,
        Table as CassandraTable, Udt,
    },
    postgres::database::Schema,
    query::Query,
};

pub struct SimpleConversion;

impl SimpleConversion {
    pub(crate) fn convert_schema_to_keyspace(schema: &Schema) -> Keyspace {
        let mut keyspace = Keyspace::new(
            schema.name().to_string(),
            Replication::new(Strategy::Simple("1".to_string()), true),
        );

        let mut cassandra_tables = Vec::new();

        for table in schema.tables().iter() {
            let mut columns = Vec::new();

            for column in table.columns().iter() {
                let mut cassandra_column_definition = CassandraColumnDefinition::new(
                    column.name().to_string(),
                    (*column.r#type()).clone().into(),
                );
                cassandra_column_definition.set_uuid(column.uuid());
                columns.push(cassandra_column_definition);
            }

            let mut cassandra_table = CassandraTable::new(table.name().to_string(), columns);
            cassandra_table.set_uuid(table.uuid());

            cassandra_tables.push(cassandra_table);
        }
        keyspace.set_tables(cassandra_tables);

        for composite in schema.composites() {
            let mut types = Vec::new();
            let fields = composite.fields();
            for field in fields {
                let name = field.name();
                let type_ = field.r#type();
                types.push((name.to_string(), (*type_).clone().into()));
            }
            let udt = Udt::new(
                schema.name().to_string(),
                composite.name().to_string(),
                types,
            );
        }

        keyspace
    }

    fn perform_conversion(
        converted_keyspace: &Keyspace,
        table_files: &HashMap<CassandraTable, PathBuf>,
        create_keyspace_file: PathBuf,
        output_directory: PathBuf,
    ) -> Result<(), Box<dyn Error>> {
        let create_keyspace_statement = converted_keyspace.to_query_string();
        let mut file = File::options()
            .create(true)
            .truncate(true)
            .write(true)
            .open(create_keyspace_file)?;

        file.write_all(create_keyspace_statement.as_bytes())?;

        for (table, file_name) in table_files.iter() {
            let mut outfile_path = output_directory.clone();
            outfile_path.push(format!("{}_cassandra.csv", table.name()));
            let mut reader = ReaderBuilder::new()
                .quote(b'\"')
                .escape(Some(b'\"'))
                .has_headers(true)
                .from_path(file_name)?;
            // Will need to write headers manually.
            let writer = WriterBuilder::new()
                .quote(b'\"')
                .escape(b'\\')
                .double_quote(true)
                .from_path(outfile_path)?;

            let columns = table.columns();
            let headers = reader.headers()?;
            let mut column_index_map = HashMap::new();
            for (index, header) in headers.iter().enumerate() {
                column_index_map.insert(header, index);
            }

            for row in reader.records() {
                let row = row?;
                for column_definition in columns.iter() {
                    let column_name = column_definition.name();
                    let column_type = column_definition.r#type();
                }
            }
        }

        Ok(())
    }
}
