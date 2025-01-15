use std::collections::HashMap;
use std::fmt::Write;

use itertools::Itertools;
use uuid::Uuid;

use crate::{cassandra::types::Type, query::Query};

#[derive(Debug, Clone)]
pub struct Keyspace {
    name: String,
    replication: Replication,
    udts: Vec<Udt>,
    tables: Vec<Table>,
}

impl Keyspace {
    pub fn new(name: String, replication: Replication) -> Self {
        Self {
            name,
            replication,
            udts: Vec::new(),
            tables: Vec::new(),
        }
    }

    pub fn set_udts(&mut self, udts: Vec<Udt>) {
        self.udts = udts;
    }

    pub fn set_tables(&mut self, tables: Vec<Table>) {
        self.tables = tables;
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn replication(&self) -> &Replication {
        &self.replication
    }

    pub fn udts(&self) -> &Vec<Udt> {
        &self.udts
    }
    pub fn tables(&self) -> &Vec<Table> {
        &self.tables
    }
    pub fn table_by_uuid(&self, uuid: Uuid) -> Option<&Table> {
        self.tables.iter().find(|&table| table.uuid == uuid)
    }
    pub fn table_by_coldef_uuid(&self, uuid: Uuid) -> Option<&Table> {
        self.tables
            .iter()
            .find(|table| table.columns.iter().any(|column| column.uuid == uuid))
    }
    pub fn coldef_by_uuid(&self, uuid: Uuid) -> Option<&ColumnDefinition> {
        let mut column = None;
        for table in self.tables.iter() {
            column = table.columns.iter().find(|&column| column.uuid == uuid);
            if column.is_some() {
                break;
            }
        }
        column
    }

    pub fn find_udt_definition(&self, udt_name: &str) -> Option<&Udt> {
        self.udts.iter().find(|u| u.name == udt_name)
    }

    fn to_query_keyspace_segment(&self, r_query: &mut String) {
        write!(r_query, "CREATE KEYSPACE {} ", self.name).unwrap();
        write!(r_query, "WITH REPLICATION = ").unwrap();
        match &self.replication.strategy {
            Strategy::Simple(s) => {
                write!(
                    r_query,
                    "{{ 'class': 'SimpleStrategy', 'replication_factor': {s} }}"
                )
                .unwrap();
            }
            Strategy::NetworkTopology(configuration) => {
                write!(r_query, "{{ class: 'NetworkTopologyStrategy', ").unwrap();
                let entry_count = configuration.len();
                for (i, (k, v)) in configuration.iter().enumerate() {
                    if i == entry_count - 1 {
                        write!(r_query, "'{k}' : {v}").unwrap();
                    } else {
                        write!(r_query, "'{k}' : '{v}', ").unwrap();
                    }
                }
                write!(r_query, "}}").unwrap();
            }
        }
        if self.replication.durable_writes {
            write!(r_query, " AND DURABLE_WRITES = true;").unwrap();
        } else {
            write!(r_query, " AND DURABLE_WRITES = false;").unwrap();
        }
    }

    fn to_query_udts(&self, r_query: &mut String) {
        for udt in self.udts.iter() {
            write!(r_query, "CREATE TYPE {}.{} (", self.name, udt.name).unwrap();
            writeln!(r_query).unwrap();
            let field_len = udt.types.len();
            for (field_idx, (field, type_)) in udt.types.iter().enumerate() {
                if field_idx == field_len - 1 {
                    write!(r_query, "\t{} {}", field, type_).unwrap();
                } else {
                    write!(r_query, "\t{} {},", field, type_).unwrap();
                }
            }
            writeln!(r_query).unwrap();
            write!(r_query, ");").unwrap();
        }
    }

    fn to_query_tables(&self, r_query: &mut String) {
        for table in self.tables.iter() {
            let column_count = table.columns.len();
            write!(r_query, "CREATE TABLE {}.{} (", self.name, table.name).unwrap();
            writeln!(r_query).unwrap();
            for (i, column) in table.columns.iter().enumerate() {
                if i == column_count - 1 {
                    writeln!(r_query, "\t{} {}", column.name, column.r#type).unwrap();
                } else {
                    writeln!(r_query, "\t{} {},", column.name, column.r#type).unwrap();
                }
            }
            let clustering_keys = table
                .columns()
                .iter()
                .filter(|c| c.clustering_key)
                .collect::<Vec<_>>();
            let partition_keys = table
                .columns()
                .iter()
                .filter(|c| c.partition_key)
                .collect::<Vec<_>>();

            write!(r_query, "\tPRIMARY KEY ").unwrap();
            if clustering_keys.is_empty() && partition_keys.len() == 1 {
                write!(r_query, "({})", partition_keys[0].name).unwrap();
            } else if partition_keys.len() > 1 && clustering_keys.is_empty() {
                write!(
                    r_query,
                    "(({}))",
                    partition_keys.iter().map(|c| c.name.clone()).join(", ")
                )
                .unwrap();
            } else {
                write!(
                    r_query,
                    "(({}), {})",
                    partition_keys.iter().map(|c| c.name.clone()).join(", "),
                    clustering_keys.iter().map(|c| c.name.clone()).join(", ")
                )
                .unwrap();
            }

            // TODO: Add clustering order by clauses.
            writeln!(r_query).unwrap();
            writeln!(r_query, ");").unwrap();
            writeln!(r_query).unwrap();
        }
    }
}

impl Query for Keyspace {
    fn to_query_string(&self) -> String {
        let mut query = String::new();
        let r_query = &mut query;
        self.to_query_keyspace_segment(r_query);
        writeln!(r_query).unwrap();
        if !self.udts.is_empty() {
            self.to_query_udts(r_query);
        }
        writeln!(r_query).unwrap();
        self.to_query_tables(r_query);
        query
    }
}

#[derive(Debug, Clone)]
pub struct Udt {
    name: String,
    keyspace: String,
    types: Vec<(String, Type)>,
}

impl Udt {
    pub fn new(keyspace: String, name: String, types: Vec<(String, Type)>) -> Self {
        Self {
            name,
            keyspace,
            types,
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn keyspace(&self) -> &str {
        &self.keyspace
    }

    pub fn types(&self) -> &Vec<(String, Type)> {
        &self.types
    }
}

#[derive(Debug, Clone)]
pub struct Replication {
    durable_writes: bool,
    strategy: Strategy,
}

impl Replication {
    pub fn new(strategy: Strategy, durable_writes: bool) -> Self {
        Self {
            durable_writes,
            strategy,
        }
    }

    pub fn durable_writes(&self) -> bool {
        self.durable_writes
    }

    pub fn strategy(&self) -> &Strategy {
        &self.strategy
    }
}

#[derive(Debug, Clone, Copy)]
pub enum OrderBy {
    Asc,
    Desc,
}

#[derive(Debug, Clone)]
pub struct Table {
    name: String,
    columns: Vec<ColumnDefinition>,
    uuid: Uuid,
}

impl Table {
    pub fn new(name: String, columns: Vec<ColumnDefinition>) -> Self {
        let uuid = Uuid::new_v4();
        Self {
            name,
            columns,
            uuid,
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn columns(&self) -> &Vec<ColumnDefinition> {
        &self.columns
    }
    pub fn uuid(&self) -> Uuid {
        self.uuid
    }
    pub fn primary_keys(&self) -> Vec<&ColumnDefinition> {
        self.columns
            .iter()
            .filter(|column| column.partition_key)
            .collect::<Vec<_>>()
    }
}

#[derive(Debug, Clone)]
pub struct ColumnDefinition {
    name: String,
    partition_key: bool,
    clustering_key: bool,
    clustering_order_by: Option<OrderBy>,
    r#type: Type,
    uuid: Uuid,
}

impl ColumnDefinition {
    pub fn new(name: String, r#type: Type) -> Self {
        let uuid = Uuid::new_v4();
        Self {
            name,
            r#type,
            clustering_key: false,
            clustering_order_by: None,
            partition_key: false,
            uuid,
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn partition_key(&self) -> bool {
        self.partition_key
    }

    pub fn set_partition_key(&mut self, partition_key: bool) {
        self.partition_key = partition_key;
    }

    pub fn clustering_key(&self) -> bool {
        self.clustering_key
    }

    pub fn set_clustering_key(&mut self, clustering_key: bool) {
        self.clustering_key = clustering_key;
    }

    pub fn clustering_order_by(&self) -> Option<OrderBy> {
        self.clustering_order_by
    }

    pub fn set_clustering_order_by(&mut self, clustering_order_by: OrderBy) {
        self.clustering_order_by = Some(clustering_order_by);
    }

    pub fn r#type(&self) -> &Type {
        &self.r#type
    }
    pub fn uuid(&self) -> Uuid {
        self.uuid
    }
}

#[derive(Debug, Clone)]
pub enum Strategy {
    Simple(String),
    NetworkTopology(HashMap<String, String>),
}
