use std::collections::HashMap;

use crate::cassandra::types::Type;

#[derive(Debug)]
pub struct Keyspace {
    name: String,
    replication: Replication,
}

impl Keyspace {
    pub fn new(name: &str, replication: Replication) -> Self {
        Self {
            name: name.to_string(),
            replication,
        }
    }
}

#[derive(Debug)]
pub struct Replication {
    durable_writes: bool,
    strategy: Strategy,
}

impl Replication {
    pub fn new(strategy: Strategy, durable_writes: bool) -> Option<Self> {
        if strategy.valid() {
            Some(Self {
                durable_writes,
                strategy,
            })
        } else {
            None
        }
    }
}

#[derive(Debug)]
pub enum OrderBy {
    Asc,
    Desc,
}

#[derive(Debug)]
pub struct Table {
    name: String,
    columns: Vec<ColumnDefinition>,
}

#[derive(Debug)]
pub struct ColumnDefinition {
    name: String,
    partition_key: bool,
    clustering_key: bool,
    clustering_order_by: Option<OrderBy>,
    r#type: Type,
    r#static: Option<bool>,
}

#[derive(Debug)]
pub enum Strategy {
    Simple(i32),
    // fact check this
    NetworkTopology(HashMap<String, i32>),
}

impl Strategy {
    fn valid(&self) -> bool {
        todo!()
    }
}
