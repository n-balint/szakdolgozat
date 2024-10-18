use tree_sitter::{Tree, TreeCursor};

use crate::cassandra::{ast_queries::table_queries::parse_type, database::Udt, types::Type};

pub fn udt_query(source: &str, tree: &Tree) -> Result<Vec<Udt>, ()> {
    let mut udts = Vec::new();
    let mut cursor = tree.walk();

    debug_assert_eq!(cursor.node().kind(), "source_file");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "create_type" {
            let keyspace_and_name = query_type_name_and_keyspace(&mut cursor, source)?;
            let split = keyspace_and_name.split('.').collect::<Vec<_>>();
            if split.get(1).is_none() {
                return Err(());
            }
            let udt = Udt::new(
                split[0],
                split[1],
                iterate_over_typed_names(source, &mut cursor)?,
            );
            udts.push(udt);
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }

    Ok(udts)
}

fn iterate_over_typed_names(
    source: &str,
    cursor: &mut TreeCursor<'_>,
) -> Result<Vec<(String, Type)>, ()> {
    debug_assert_eq!(cursor.node().kind(), "create_type");
    let original_cursor = cursor.clone();
    let mut typed_name = Vec::new();
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "typed_name" {
            let snapshot = cursor.clone();
            let split = &source[cursor.node().byte_range()]
                .split(&[' ', '\t'])
                .collect::<Vec<_>>();
            if split.first().is_none() {
                return Err(());
            };
            let name = split[0];
            move_to_data_type(cursor)?;
            move_to_cql_type(cursor)?;
            let type_ = parse_type(cursor, source)?;
            typed_name.push((name.to_string(), type_));
            cursor.reset_to(&snapshot);
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    cursor.reset_to(&original_cursor);
    Ok(typed_name)
}

fn move_to_data_type(cursor: &mut TreeCursor<'_>) -> Result<(), ()> {
    debug_assert_eq!(cursor.node().kind(), "typed_name");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "data_type" {
            return Ok(());
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    println!("move to datatype err");
    Err(())
}

fn move_to_cql_type(cursor: &mut TreeCursor<'_>) -> Result<(), ()> {
    debug_assert_eq!(cursor.node().kind(), "data_type");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "cql_type" {
            return Ok(());
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    println!("move to cqltype err");
    Err(())
}

fn query_type_name_and_keyspace(cursor: &mut TreeCursor<'_>, source: &str) -> Result<String, ()> {
    debug_assert_eq!(cursor.node().kind(), "create_type");
    let original_cursor = cursor.clone();
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "type_name" {
            let name = Ok(source[cursor.node().byte_range()].to_string());
            cursor.reset_to(&original_cursor);
            return name;
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Err(())
}
