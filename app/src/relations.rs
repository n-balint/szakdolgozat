use itertools::Itertools;
use std::{
    collections::{HashMap, HashSet},
    fs::File,
};

use polars::{frame::column, io::SerReader, prelude::CsvReadOptions};

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
    pub fn run(&self) {
        let mut relations = Relations::default();
        self.find_unique_columns(&mut relations);
        self.find_subset_columns(&mut relations);
        println!("{:#?}", relations.unique_column);
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
            let file = self.csv_file[table.name()].try_clone().unwrap();
            let dataframe = CsvReadOptions::default()
                .with_has_header(true)
                .with_low_memory(true)
                .into_reader_with_file_handle(file)
                .finish()
                .unwrap();

            for column_name in dataframe.get_column_names() {
                if key_names.contains(&column_name.trim().to_string()) {
                    continue;
                }
                let column_data = dataframe.column(column_name).unwrap();
                if column_data.unique().unwrap().len() == column_data.len() {
                    relations.unique_column.push(UniqueColumn {
                        table: table.name().to_string(),
                        column: column_name.trim().to_string(),
                        column_kind: ColumnKind::Unique,
                    });
                }
            }

            println!("{}", dataframe);
        }
    }

    fn find_subset_columns(&self, relations: &mut Relations) {
        for (&column_type, columns) in self.type_mapping.iter() {
            for (&left, &right) in columns.iter().tuple_combinations() {
                if left.uuid() == right.uuid() {
                    continue;
                }

                let left_table = self.keyspace.table_by_coldef_uuid(left.uuid()).unwrap();
                let left_csv_file = self.csv_file[&left_table.name().to_string()]
                    .try_clone()
                    .unwrap();
                let right_table = self.keyspace.table_by_coldef_uuid(right.uuid()).unwrap();
                let right_csv_table = self.csv_file[&right_table.name().to_string()]
                    .try_clone()
                    .unwrap();

                let left_dataframe = CsvReadOptions::default()
                    .with_has_header(true)
                    .with_low_memory(true)
                    .into_reader_with_file_handle(left_csv_file)
                    .finish()
                    .unwrap();

                let right_dataframe = CsvReadOptions::default()
                    .with_has_header(true)
                    .with_low_memory(true)
                    .into_reader_with_file_handle(right_csv_table)
                    .finish()
                    .unwrap();

                let left_column = left_dataframe.column(left.name()).unwrap().rechunk();
                let right_column = right_dataframe.column(right.name()).unwrap().rechunk();

                let left_series = left_column.as_series().unwrap();
                let right_series = right_column.as_series().unwrap();

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
                    println!("found subset: {}, {}", left.name(), right.name());
                }
            }
        }
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
struct SubsetColumn {
    left: InnerSubsetColumn,
    right: InnerSubsetColumn,
    left_count: u64,
    right_count: u64,
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
    foreign_keys: HashMap<(String, String), (String, String)>,
    duplicate_columns: HashMap<(String, String), Vec<(String, String)>>,
}

impl Relations {
    fn is_in_unique_column(&self, table: &str, column: &str) -> bool {
        self.unique_column
            .iter()
            .any(|unique_column| unique_column.table == table && unique_column.column == column)
    }
}
