use graph::{Graph, Node};
use uuid::Uuid;

use crate::cassandra::database::{Keyspace, Replication, Strategy};

use super::database::{ColumnDefinition, Schema};
use std::collections::HashMap;

pub mod graph;
pub mod simple_conversion;

#[derive(Debug, Clone)]
pub struct PossibleDuplicateColumn {
    should_use: bool,
    table: String,
    column: String,
    uuid: Uuid,
}

impl PossibleDuplicateColumn {
    fn new(table: String, column: String, uuid: Uuid) -> Self {
        Self {
            table,
            column,
            should_use: false,
            uuid,
        }
    }
}

#[derive(Debug, Clone)]
pub struct KeyspaceConverter {
    schema: Schema,
    keyspace: Keyspace,
    duplicates: Vec<PossibleDuplicateColumn>,
    graph: Graph<String>,
    index_map: HashMap<usize, String>,
    name_map: HashMap<String, usize>,
    expanded_schema: Schema,
}

impl KeyspaceConverter {
    pub fn new(schema: &Schema) -> Self {
        Self {
            schema: schema.clone(),
            keyspace: Keyspace::new(
                schema.name().to_string(),
                Replication::new(Strategy::Simple("1".to_string()), true),
            ),
            duplicates: Vec::new(),
            graph: Graph::new(schema.tables().len()),
            index_map: HashMap::new(),
            name_map: HashMap::new(),
            expanded_schema: schema.clone(),
        }
    }

    pub fn construct_foreign_key_graph(&mut self) {
        for (i, table) in self.schema.tables().iter().enumerate() {
            self.index_map.insert(i, table.name().to_string());
            self.name_map.insert(table.name().to_string(), i);
            self.graph.add_node(Node::new(table.name().to_string()));
        }

        for table in self.schema.tables().iter() {
            let foreign_keys = table.foreign_keys();
            for foreign_key in foreign_keys.iter() {
                let referenced_table = foreign_key.referenced_table();
                self.graph
                    .add_edge(self.name_map[table.name()], self.name_map[referenced_table]);
            }
        }
    }

    pub fn find_columns_to_duplicate(&mut self) {
        for table in self.expanded_schema.tables_mut().iter_mut() {
            let reachable_tables = self.graph.dfs(self.name_map[table.name()]);
            for reachable_table in reachable_tables.iter() {
                let reachable_table = reachable_table.data();
                let found_table = self
                    .schema
                    .tables()
                    .iter()
                    .find(|table| table.name() == reachable_table);
                if let Some(found_table) = found_table {
                    for column in found_table.columns().iter() {
                        table.add_column(column.clone());
                        self.duplicates.push(PossibleDuplicateColumn::new(
                            found_table.name().to_string(),
                            column.name().to_string(),
                            column.uuid(),
                        ));
                    }
                }
            }
        }
    }
}
