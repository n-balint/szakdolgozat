use itertools::Itertools;
use std::{
    collections::{HashMap, HashSet},
    error::Error,
    fs::File,
};

use polars::{
    frame::column,
    io::SerReader,
    prelude::{CsvReadOptions, DataType, Schema, SchemaRef},
};

use crate::cassandra::{
    database::{ColumnDefinition, Keyspace},
    types::Type,
};

#[derive(Debug, Clone)]
pub struct FindRelations<'a> {
    keyspace: &'a Keyspace,
    csv_file: &'a HashMap<String, File>,
    type_mapping: HashMap<&'a Type, Vec<&'a ColumnDefinition>>,
}

impl<'a> FindRelations<'a> {
    pub fn new(keyspace: &'a Keyspace, csv_file: &'a HashMap<String, File>) -> Self {
        let mut type_mapping: HashMap<&Type, Vec<&ColumnDefinition>> = HashMap::new();
        for table in keyspace.tables().iter() {
            for column in table.columns().iter() {
                match type_mapping.get_mut(column.r#type()) {
                    Some(definitions) => definitions.push(column),
                    None => {
                        type_mapping.insert(column.r#type(), vec![column]);
                    }
                }
            }
        }
        Self {
            keyspace,
            csv_file,
            type_mapping,
        }
    }
    pub fn run(&self) -> Result<(), Box<dyn Error>> {
        let mut relations = Relations::default();
        self.find_unique_columns(&mut relations);
        self.find_subset_columns(&mut relations)?;
        self.update_unqiue_subset_columns(&mut relations);
        println!("{:#?}", relations);
        Ok(())
    }

    fn find_unique_columns(&self, relations: &mut Relations) {
        for table in self.keyspace.tables().iter() {
            let primary_keys = table.primary_keys();
            let key_names = primary_keys
                .iter()
                .map(|column| column.name().to_string())
                .collect::<Vec<_>>();

            for key in key_names.iter() {
                relations.unique_column.push(UniqueColumn {
                    table: table.name().to_string(),
                    column: key.to_string(),
                    column_kind: ColumnKind::Key,
                });
            }
        }
    }

    fn find_subset_columns(&self, relations: &mut Relations) -> Result<(), Box<dyn Error>> {
        for (_, columns) in self.type_mapping.iter() {
            for (&left, &right) in columns.iter().tuple_combinations() {
                if left.uuid() == right.uuid() {
                    continue;
                }

                let left_table = self
                    .keyspace
                    .table_by_coldef_uuid(left.uuid())
                    .expect("Column should be in the table.");
                let left_csv_file = self.csv_file[&left_table.name().to_string()].try_clone()?;
                let right_table = self
                    .keyspace
                    .table_by_coldef_uuid(right.uuid())
                    .expect("Column should be in the table.");
                let right_csv_table = self.csv_file[&right_table.name().to_string()].try_clone()?;

                let left_dataframe = CsvReadOptions::default()
                    .with_has_header(true)
                    .with_low_memory(true)
                    .into_reader_with_file_handle(left_csv_file)
                    .finish()?;

                let right_dataframe = CsvReadOptions::default()
                    .with_has_header(true)
                    .with_low_memory(true)
                    .into_reader_with_file_handle(right_csv_table)
                    .finish()?;

                let left_column = left_dataframe.column(left.name())?.rechunk();
                let right_column = right_dataframe.column(right.name())?.rechunk();

                let left_series = left_column
                    .as_series()
                    .expect("After rechunking it should be able to be converted into a series.");
                let right_series = right_column
                    .as_series()
                    .expect("After rechunking it should be able to be converted into a series.");

                let left_count = left_series.len();
                let right_count = right_series.len();

                // cannot use polars for this, api is not yet implemented in rust

                let left_set = left_series.iter().collect::<HashSet<_>>();
                let right_set = right_series.iter().collect::<HashSet<_>>();

                let is_subset = if left_set.len() <= right_set.len() {
                    left_set.is_subset(&right_set)
                } else {
                    right_set.is_subset(&left_set)
                };

                if is_subset {
                    relations.subsets.push(SubsetColumn {
                        // the unique will be an option and processed at a later time
                        left: InnerSubsetColumn {
                            table: self
                                .keyspace
                                .table_by_coldef_uuid(left.uuid())
                                .unwrap()
                                .name()
                                .to_string(),
                            column: left.name().to_string(),
                            unique: false,
                        },
                        right: InnerSubsetColumn {
                            table: self
                                .keyspace
                                .table_by_coldef_uuid(right.uuid())
                                .unwrap()
                                .name()
                                .to_string(),
                            column: right.name().to_string(),
                            unique: false,
                        },
                        left_count,
                        right_count,
                        is_true: false,
                    });
                }
            }
        }
        Ok(())
    }

    fn update_unqiue_subset_columns(&self, relations: &mut Relations) {
        let tables = self.keyspace.tables();
        relations.subsets.iter_mut().for_each(|subset_column| {
            subset_column.left.unique = tables
                .iter()
                .find(|&table| table.name() == subset_column.left.table)
                .expect("Table should be in the keyspace")
                .columns()
                .iter()
                .find(|&column_definition| column_definition.name() == subset_column.left.column)
                .expect("Column should be in the table")
                .partition_key();

            subset_column.right.unique = tables
                .iter()
                .find(|&table| table.name() == subset_column.right.table)
                .expect("Table should be in the keyspace")
                .columns()
                .iter()
                .find(|&column_definition| column_definition.name() == subset_column.right.column)
                .expect("Column should be in the table")
                .partition_key();
        });
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum ColumnKind {
    Key,
    Unique,
}

#[derive(Debug, Clone)]
struct UniqueColumn {
    table: String,
    column: String,
    column_kind: ColumnKind,
}

#[derive(Debug, Clone)]
pub struct SubsetColumn {
    left: InnerSubsetColumn,
    right: InnerSubsetColumn,
    left_count: usize,
    right_count: usize,
    is_true: bool,
}

#[derive(Debug, Clone)]
struct InnerSubsetColumn {
    table: String,
    column: String,
    unique: bool,
}

#[derive(Debug, Clone, Default)]
pub struct Relations {
    unique_column: Vec<UniqueColumn>,
    subsets: Vec<SubsetColumn>,
}

impl Relations {
    fn is_in_unique_column(&self, table: &str, column: &str) -> bool {
        self.unique_column
            .iter()
            .any(|unique_column| unique_column.table == table && unique_column.column == column)
    }

    pub fn subsets(&self) -> &Vec<SubsetColumn> {
        &self.subsets
    }
}
