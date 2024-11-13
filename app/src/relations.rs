use std::collections::HashMap;

use crate::cassandra::{
    database::{ColumnDefinition, Keyspace},
    types::Type,
};

struct RelationCandidate<'a> {
    relations: Vec<&'a ColumnDefinition>,
}

fn get_relation_candidates(keyspace: &Keyspace) -> Vec<RelationCandidate<'_>> {
    let mut type_mapping: HashMap<&Type, Vec<&ColumnDefinition>> = HashMap::new();
    let mut candidates = Vec::new();
    for table in keyspace.tables().iter() {
        for column in table.columns().iter() {
            match type_mapping.get_mut(column.r#type()) {
                Some(v) => {
                    v.push(column);
                }
                None => {
                    type_mapping.insert(column.r#type(), vec![column]);
                }
            };
        }
    }

    for (_, v) in type_mapping.into_iter() {
        candidates.push(RelationCandidate { relations: v });
    }

    candidates
}

struct Relation {}
