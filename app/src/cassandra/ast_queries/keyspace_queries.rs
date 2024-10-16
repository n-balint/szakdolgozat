use std::collections::HashMap;

use tree_sitter::{Tree, TreeCursor};

use crate::cassandra::database::{Replication, Strategy};

use crate::cassandra::database::Keyspace;

pub fn keyspace_query(source: &str, node: &Tree) -> Result<Keyspace, ()> {
    let mut cursor = node.walk();
    let keyspace_name = get_keyspace_name(&mut cursor, source)?;
    let replication_list = get_replication_list_items(&mut cursor, source)?;
    let durable_writes = get_durable_writes(&mut cursor, source);
    let mut replication_map: HashMap<String, String> = HashMap::new();

    for pair in replication_list.iter() {
        let split = pair
            .split(":")
            .collect::<Vec<_>>()
            .iter()
            .map(|&s| s.trim())
            .collect::<Vec<_>>();
        if split.len() != 2 {
            return Err(());
        }
        replication_map.insert(split[0].to_string(), split[1].to_string());
    }

    let replication_class = replication_map
        .iter()
        .filter(|(k, _)| &k[..] == "'class'")
        .map(|(k, v)| (k.clone(), v.clone()))
        .collect::<Vec<_>>();

    if replication_class.len() != 1 {
        return Err(());
    }

    replication_map.remove(&replication_class[0].0);

    println!("patternmatcherr");
    let strategy = match &replication_class[0].1[..] {
        "'SimpleStrategy'" => {
            if let Some(factor) = replication_map.get("'replication_factor'") {
                Strategy::Simple(factor.clone())
            } else {
                return Err(());
            }
        }
        "'NetworkTopologyStrategy'" => Strategy::NetworkTopology(replication_map),
        _ => return Err(()),
    };

    let replication = Replication::new(strategy, durable_writes);
    Ok(Keyspace::new(&keyspace_name, replication))
}

/// Returns the name of the first keyspace encountered. Moves the cursor back to create_keyspace
/// (parent). The starter node must be the root `(source_file)`
fn get_keyspace_name(cursor: &mut TreeCursor<'_>, source: &str) -> Result<String, ()> {
    debug_assert_eq!(cursor.node().kind(), "source_file");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "create_keyspace" {
            cursor.goto_first_child();
            loop {
                if cursor.node().kind() == "keyspace_name" {
                    let keyspace_name = Ok(source[cursor.node().byte_range()].to_string());
                    cursor.goto_parent();
                    debug_assert_eq!(cursor.node().kind(), "create_keyspace");
                    return keyspace_name;
                }

                if !cursor.goto_next_sibling() {
                    break;
                }
            }
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Err(())
}
/// Return the replication list items. The cursor must point to `(create_keyspace)`. In the end it
/// moves the cursor back to `(create_keyspace)`.
fn get_replication_list_items(
    cursor: &mut TreeCursor<'_>,
    source: &str,
) -> Result<Vec<String>, ()> {
    let mut replication_list_items = Vec::new();
    debug_assert_eq!(cursor.node().kind(), "create_keyspace");

    // move into keyspace definition list
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "replication_list" {
            cursor.goto_first_child();
            loop {
                if cursor.node().kind() == "replication_list_item" {
                    replication_list_items.push(source[cursor.node().byte_range()].to_string());
                }
                if !cursor.goto_next_sibling() {
                    // to replication_list
                    cursor.goto_parent();
                    // to create_keyspace
                    cursor.goto_parent();
                    debug_assert_eq!(cursor.node().kind(), "create_keyspace");
                    return Ok(replication_list_items);
                }
            }
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Err(())
}

/// Returns whether durable writes are enabled or not. The cursor must point to
/// `(create_keyspace)`. The cursor will be returned to `(source_file)`.
fn get_durable_writes(cursor: &mut TreeCursor<'_>, source: &str) -> bool {
    debug_assert_eq!(cursor.node().kind(), "create_keyspace");

    // move into keyspace definition list
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "durable_writes" {
            // text value looks like "durable_writes = {TRUE, FALSE}"
            let text_value = &source[cursor.node().byte_range()];

            let enabled = text_value
                .split("=")
                .collect::<Vec<_>>()
                .get(1)
                .map(|&x| Some(x.trim().to_uppercase() == "TRUE"))
                .is_some();

            // move back to
            cursor.goto_parent();
            return enabled;
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    false
}

#[cfg(test)]
mod test {
    use tree_sitter::Parser;

    use super::*;
    #[test]
    fn test_without_durable_clause() {
        let stmt = "
        CREATE KEYSPACE books WITH replication = {'class': 'NetworkTopologyStrategy', 'DC1' : '2', 'DC3' : '5'};
        ";

        let mut parser = Parser::new();
        parser.set_language(&tree_sitter_cql::language()).unwrap();
        let tree = parser.parse(stmt, None).unwrap();
        let mut cursor = tree.walk();
        let name = get_keyspace_name(&mut cursor, stmt);
        let replication = get_replication_list_items(&mut cursor, stmt);
        let durable = get_durable_writes(&mut cursor, stmt);

        assert_eq!(name, Ok("books".to_string()));
        assert_eq!(
            replication,
            Ok(vec![
                "'class': 'NetworkTopologyStrategy'".to_string(),
                "'DC1' : '2'".to_string(),
                "'DC3' : '5'".to_string()
            ])
        );
        assert!(!durable);
    }
}
