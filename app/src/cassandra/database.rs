use std::collections::HashMap;

use crate::cassandra::types::Type;

#[derive(Debug, Clone)]
pub struct Keyspace {
    name: String,
    replication: Replication,
    udts: Vec<Udt>,
}

impl Keyspace {
    pub fn new(name: &str, replication: Replication) -> Self {
        Self {
            name: name.to_string(),
            replication,
            udts: Vec::new(),
        }
    }
}

#[derive(Debug, Clone)]
pub struct Udt {
    name: String,
    types: Vec<(String, Box<Type>)>,
}

impl Udt {
    pub fn new(name: &str) -> Self {
        Self {
            name: name.to_string(),
            types: Vec::new(),
        }
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
    pub fn new(name: &str, columns: Vec<ColumnDefinition>) -> Self {
        Self {
            name: name.to_string(),
            columns,
        }
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
    pub fn new(name: &str, r#type: Type) -> Self {
        Self {
            name: name.to_string(),
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
