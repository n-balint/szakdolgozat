use std::collections::HashMap;

use crate::cassandra::types::Type;

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
}

impl Table {
    pub fn new(name: String, columns: Vec<ColumnDefinition>) -> Self {
        Self { name, columns }
    }

    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn columns(&self) -> &Vec<ColumnDefinition> {
        &self.columns
    }
}

#[derive(Debug, Clone)]
pub struct ColumnDefinition {
    name: String,
    partition_key: bool,
    clustering_key: bool,
    clustering_order_by: Option<OrderBy>,
    r#type: Type,
}

impl ColumnDefinition {
    pub fn new(name: String, r#type: Type) -> Self {
        Self {
            name,
            r#type,
            clustering_key: false,
            clustering_order_by: None,
            partition_key: false,
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
}

#[derive(Debug, Clone)]
pub enum Strategy {
    Simple(String),
    NetworkTopology(HashMap<String, String>),
}
