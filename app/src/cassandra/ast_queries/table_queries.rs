use tree_sitter::{Tree, TreeCursor};

use crate::{
    cassandra::{
        database::{ColumnDefinition, Table},
        types::{CollectionType, PrimitiveType, Type},
    },
    util::ast::move_to_node,
};

pub fn table_query(source: &str, node: &Tree) -> Result<Vec<Table>, ()> {
    let mut cursor = node.walk();
    let mut tables = Vec::new();
    debug_assert_eq!(cursor.node().kind(), "source_file");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "create_table" {
            let snapshot = cursor.clone();
            let name = get_table_name(&mut cursor, source)?;
            move_to_column_definition_list(&mut cursor)?;
            let column_definition = get_column_definitions(&mut cursor, source)?;
            tables.push(Table::new(name, column_definition));
            cursor.reset_to(&snapshot);
            println!("{}", cursor.node().kind());
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Ok(tables)
}

/// This function retrieves the name of the current table. The cursor should point to a
/// `(create_table)` node. It returns with the cursor set back to the `(create_table)` node.
fn get_table_name(cursor: &mut TreeCursor<'_>, source: &str) -> Result<String, ()> {
    debug_assert_eq!(cursor.node().kind(), "create_table");
    let original_cursor = cursor.clone();
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "table_name" {
            let mut name = source[cursor.node().byte_range()].to_string();
            if name.contains('.') {
                let split = name.split('.').collect::<Vec<_>>();
                match split.get(1) {
                    Some(n) => name = n.to_string(),
                    None => return Err(()),
                }
            }
            cursor.reset_to(&original_cursor);
            debug_assert_eq!(cursor.node().kind(), "create_table");
            return Ok(name);
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    cursor.goto_parent();
    println!("get_table_name error");
    Err(())
}

fn move_to_column_definition_list(cursor: &mut TreeCursor<'_>) -> Result<(), ()> {
    debug_assert_eq!(cursor.node().kind(), "create_table");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "column_definition_list" {
            return Ok(());
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    println!("move_to_column_definition_list errror");
    Err(())
}

#[derive(Debug, Clone, PartialEq)]
enum Keys {
    Single(String),
    Compound(String, Vec<String>),
    Composite(Vec<String>, Vec<String>),
}

fn parse_key_list(input: &str) -> Vec<String> {
    input.split(',').map(|s| s.trim().to_string()).collect()
}

fn parse_key_single(input: &str) -> Option<Keys> {
    let input = input.trim();
    if input.chars().all(|c| c.is_alphanumeric()) {
        Some(Keys::Single(input.to_string()))
    } else {
        None
    }
}

fn parse_key_compound(input: &str) -> Option<Keys> {
    let keys = parse_key_list(input);
    if keys.len() > 1 {
        let partition_key = keys[0].clone();
        let clustering_keys = keys[1..].to_vec();
        Some(Keys::Compound(partition_key, clustering_keys))
    } else {
        None
    }
}

fn parse_key_composite(input: &str) -> Option<Keys> {
    if let Some(p_open) = input.find('(') {
        if let Some(p_close) = input.find(')') {
            let partition_keys_segment = &input[p_open + 1..p_close];
            let clustering_keys_segment = input[p_close + 1..].trim_start_matches(',').trim();

            let partition_keys = parse_key_list(partition_keys_segment);
            let clustering_keys = parse_key_list(clustering_keys_segment);
            println!("p:{:#?}", partition_keys);
            println!("c:{:#?}", clustering_keys);
            if !partition_keys.is_empty() && !clustering_keys.is_empty() {
                return Some(Keys::Composite(partition_keys, clustering_keys));
            }
        }
    }
    None
}

fn parse_primary_keys_clause(input: &str) -> Option<Keys> {
    let input = input.trim();
    if input.starts_with('(') {
        parse_key_composite(input)
    } else if input.contains(',') {
        parse_key_compound(input)
    } else {
        parse_key_single(input)
    }
}

fn get_column_definitions(
    cursor: &mut TreeCursor<'_>,
    source: &str,
) -> Result<Vec<ColumnDefinition>, ()> {
    debug_assert_eq!(cursor.node().kind(), "column_definition_list");
    let mut column_definitions = Vec::new();

    let keys_cursor_snapshot = cursor.clone();
    cursor.goto_first_child();
    let _ = move_to_node(cursor, "primary_key_element");
    cursor.goto_first_child();
    let _ = move_to_node(cursor, "primary_key_definition");
    let keys = parse_primary_keys_clause(&source[cursor.node().byte_range()]);

    cursor.reset_to(&keys_cursor_snapshot);
    cursor.goto_first_child();

    loop {
        if cursor.node().kind() == "column_definition" {
            let name = source[cursor.node().byte_range()]
                .split(&[' ', '\t'])
                .collect::<Vec<_>>();
            if name.first().is_none() {
                return Err(());
            }
            let name = name[0];
            let original_cursor = cursor.clone();

            cursor.goto_first_child();
            let primary_key_snapshot = cursor.clone();
            let mut is_primary_key = false;
            loop {
                if cursor.node().kind() == "primary_key_column" {
                    is_primary_key = true;
                    break;
                }
                if !cursor.goto_next_sibling() {
                    break;
                }
            }
            cursor.reset_to(&primary_key_snapshot);
            loop {
                if cursor.node().kind() == "data_type" {
                    break;
                }
                if !cursor.goto_next_sibling() {
                    println!("get_coldef data type err");
                    return Err(());
                }
            }
            debug_assert_eq!(cursor.node().kind(), "data_type");

            cursor.goto_first_child();
            loop {
                if cursor.node().kind() == "cql_type" {
                    break;
                }
                if !cursor.goto_next_sibling() {
                    println!("get_coldef cqltype err");
                    return Err(());
                }
            }
            debug_assert_eq!(cursor.node().kind(), "cql_type");

            let type_ = parse_type(cursor, source)?;
            let mut column_definition = ColumnDefinition::new(name.to_string(), type_);
            column_definition.set_partition_key(is_primary_key);
            column_definitions.push(column_definition);
            cursor.reset_to(&original_cursor);
        }

        if !cursor.goto_next_sibling() {
            break;
        }
    }
    if let Some(keys) = keys {
        match keys {
            Keys::Single(name) => {
                if let Some(c) = column_definitions.iter_mut().find(|c| c.name() == name) {
                    c.set_partition_key(true)
                }
            }
            Keys::Compound(partition_key, clustering_keys) => {
                if let Some(c) = column_definitions
                    .iter_mut()
                    .find(|c| c.name() == partition_key)
                {
                    c.set_partition_key(true);
                }
                for key in clustering_keys.iter() {
                    if let Some(c) = column_definitions.iter_mut().find(|c| c.name() == key) {
                        c.set_clustering_key(true);
                    }
                }
            }
            Keys::Composite(partition_keys, clustering_keys) => {
                for partition_key in partition_keys.iter() {
                    if let Some(c) = column_definitions
                        .iter_mut()
                        .find(|c| c.name() == partition_key)
                    {
                        c.set_partition_key(true);
                    }
                }
                for clustering_key in clustering_keys.iter() {
                    if let Some(c) = column_definitions
                        .iter_mut()
                        .find(|c| c.name() == clustering_key)
                    {
                        c.set_clustering_key(true);
                    }
                }
            }
        }
    }
    Ok(column_definitions)
}

fn skip_anon_tokens(cursor: &mut TreeCursor<'_>) {
    while !cursor.node().is_named() {
        cursor.goto_next_sibling();
    }
}

pub fn parse_type(cursor: &mut TreeCursor<'_>, source: &str) -> Result<Type, ()> {
    // this is the base case in recursive cases the cursor is already on the child type
    skip_anon_tokens(cursor);
    if cursor.node().kind() == "cql_type" {
        cursor.goto_first_child();
    }
    // skip non-named tokens like ','' '<' '>'
    skip_anon_tokens(cursor);
    match cursor.node().kind() {
        "native_type" => {
            let typename = &source[cursor.node().byte_range()];
            let primitive_type: PrimitiveType = typename.try_into()?;
            Ok(Type::Primitive(primitive_type))
        }
        "collection_type" => {
            cursor.goto_first_child();
            let collection_type_str = &source[cursor.node().byte_range()];
            cursor.goto_next_sibling();

            let snapshot = cursor.clone();
            let type1 = parse_type(cursor, source)?;
            cursor.reset_to(&snapshot);
            match collection_type_str {
                "list" => Ok(Type::Collection {
                    frozen: false,
                    r#type: CollectionType::List(Box::new(type1)),
                }),
                "set" => Ok(Type::Collection {
                    frozen: false,
                    r#type: CollectionType::Set(Box::new(type1)),
                }),
                "map" => {
                    skip_anon_tokens(cursor);
                    cursor.goto_next_sibling();
                    skip_anon_tokens(cursor);
                    let type2 = parse_type(cursor, source)?;
                    Ok(Type::Collection {
                        frozen: false,
                        r#type: CollectionType::Map(Box::new(type1), Box::new(type2)),
                    })
                }
                _ => Err(()),
            }
        }
        "tuple_type" => {
            let mut types = Vec::new();
            cursor.goto_first_child();
            skip_anon_tokens(cursor);
            loop {
                let snapshot = cursor.clone();
                types.push(parse_type(cursor, source)?);
                cursor.reset_to(&snapshot);
                cursor.goto_next_sibling();
                if !cursor.goto_next_sibling() {
                    break;
                }
            }
            Ok(Type::Tuple(types))
        }
        "frozen_type" => {
            cursor.goto_first_child();
            let frozen_type = parse_type(cursor, source)?;
            match frozen_type {
                Type::Collection { r#type, .. } => Ok(Type::Collection {
                    frozen: true,
                    r#type,
                }),
                Type::Tuple(tuple_types) => Ok(Type::Tuple(tuple_types)),
                Type::Udt { name, keyspace, .. } => Ok(Type::Udt {
                    frozen: true,
                    name,
                    keyspace,
                }),
                _ => Err(()),
            }
        }
        "user_defined_type" => {
            let udt_name = &source[cursor.node().byte_range()];
            let name;
            let mut keyspace = "";
            if udt_name.contains('.') {
                let split = udt_name.split('.').collect::<Vec<_>>();
                if split.len() != 2 {
                    return Err(());
                }
                keyspace = split[0];
                name = split[1];
            } else {
                name = udt_name;
            }
            Ok(Type::Udt {
                frozen: false,
                name: name.to_string(),
                keyspace: keyspace.to_string(),
            })
        }
        _ => Err(()),
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_parse_single_key() {
        assert_eq!(
            parse_primary_keys_clause("a"),
            Some(Keys::Single("a".to_string()))
        );
    }

    #[test]
    fn test_parse_compound_key() {
        assert_eq!(
            parse_primary_keys_clause("a, b, c, d"),
            Some(Keys::Compound(
                "a".to_string(),
                vec!["b", "c", "d"]
                    .into_iter()
                    .map(|c| c.to_string())
                    .collect()
            ))
        )
    }
    #[test]
    fn test_parse_composite_key() {
        assert_eq!(
            parse_primary_keys_clause("(a, b, c), d, e"),
            Some(Keys::Composite(
                vec!["a", "b", "c"]
                    .into_iter()
                    .map(|c| c.to_string())
                    .collect(),
                vec!["d", "e"].into_iter().map(|c| c.to_string()).collect()
            ))
        );
    }
}
