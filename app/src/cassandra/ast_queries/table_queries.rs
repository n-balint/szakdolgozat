use tree_sitter::{Tree, TreeCursor};

use crate::cassandra::{
    database::{ColumnDefinition, Table},
    types::{CollectionType, PrimitiveType, Type},
};

pub fn table_query(source: &str, node: &Tree) -> Result<Vec<Table>, ()> {
    let mut cursor = node.walk();
    let mut tables = Vec::new();
    debug_assert_eq!(cursor.node().kind(), "source_file");
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "create_table" {
            let name = get_table_name(&mut cursor, source)?;
            move_to_column_definition_list(&mut cursor)?;
            let column_definition = get_column_definitions(&mut cursor, source)?;
            tables.push(Table::new(&name, column_definition));
            cursor.goto_parent();
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
            let name = Ok(source[cursor.node().byte_range()].to_string());
            cursor.reset_to(&original_cursor);
            debug_assert_eq!(cursor.node().kind(), "create_table");
            return name;
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

fn get_column_definitions(
    cursor: &mut TreeCursor<'_>,
    source: &str,
) -> Result<Vec<ColumnDefinition>, ()> {
    debug_assert_eq!(cursor.node().kind(), "column_definition_list");
    let mut column_definitions = Vec::new();
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
            let column_definition = ColumnDefinition::new(name, type_);
            column_definitions.push(column_definition);
            cursor.reset_to(&original_cursor);
        }

        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Ok(column_definitions)
}

fn parse_type(cursor: &mut TreeCursor<'_>, source: &str) -> Result<Type, ()> {
    // skip non-named tokens like ','' '<' '>'
    while !cursor.node().is_named() {
        cursor.goto_next_sibling();
    }
    // this is the base case in recursive cases the cursor is already on the child type
    if cursor.node().kind() == "cql_type" {
        cursor.goto_first_child();
    }
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

            let type1 = parse_type(cursor, source)?;
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
                    cursor.goto_next_sibling();
                    cursor.goto_next_sibling();
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
            cursor.goto_first_child();
            let mut types = Vec::new();
            loop {
                let tuple_element = parse_type(cursor, source)?;
                types.push(tuple_element);
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
            let split = udt_name.split('.').collect::<Vec<_>>();
            if split.get(1).is_none() {
                return Err(());
            }
            let keyspace = split[0].to_string();
            let name = split[1].to_string();
            Ok(Type::Udt {
                frozen: false,
                name,
                keyspace,
            })
        }
        _ => Err(()),
    }
}
