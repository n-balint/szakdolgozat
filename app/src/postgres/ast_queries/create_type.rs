use std::collections::{HashMap, HashSet};

use itertools::Itertools;
use tree_sitter::{Node, Query, QueryCursor};
fn dedup(v: &mut Vec<String>) {
    let mut set = HashSet::new();

    v.retain(|x| set.insert(x.clone()));
}

fn parse_create_type_enum(source: &str, node: &Node) {
    let query_str = r#"
        (statement
          (create_type
            (object_reference
             name: (identifier)@type_name)
            (keyword_as)
            (keyword_enum)
            (enum_elements
              enum_element: (literal)@enum_literal)))
    "#;

    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    let mut seen: HashMap<String, Vec<String>> = HashMap::new();

    for (capture, _idx) in captures {
        let mut type_name = None;
        let mut enum_literal = None;

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            match capture_name {
                "type_name" => type_name = Some(value),
                "enum_literal" => enum_literal = Some(value),
                _ => panic!("Found unknown capture target. Check the query."),
            }
        }

        if let (Some(type_name), Some(enum_literal)) = (type_name, enum_literal) {
            seen.entry(type_name).or_default().push(enum_literal);
        }
    }

    for (_, v) in seen.iter_mut() {
        dedup(v);
    }
}

fn parse_create_type_composite(source: &str, node: &Node) {
    let query_str = r#"
        (statement
          (create_type
            (object_reference
             name: (identifier)@type_name)
            (keyword_as)
            (column_definitions
              (column_definition
               name: (identifier)@field_name
               type: (_)@field_type
               type: ((array_size_definition)@array)?)
               )))
    "#;

    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    let mut seen = HashSet::new();

    for (capture, _idx) in captures {
        let mut type_name = None;
        let mut field_name = None;
        let mut field_type = None;
        let mut array = Some(String::new());

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            println!("{}", value);

            match capture_name {
                "type_name" => type_name = Some(value),
                "field_name" => field_name = Some(value),
                "field_type" => field_type = Some(value),
                "array" => array = Some(value),
                _ => panic!("Found unknown capture target. Check the query."),
            }
        }

        if let (Some(type_name), Some(field_name), Some(field_type), Some(array)) =
            (type_name, field_name, field_type, array)
        {
            let entry = (type_name, field_name, field_type, array);
            if !seen.contains(&entry) {
                seen.insert(entry);
            }
        }
    }

    println!("{:#?}", seen);
}

#[cfg(test)]
mod test {
    use tree_sitter::Parser;

    use super::*;
    #[test]
    fn test_create_enum() {
        let source = r#"
            CREATE TYPE mood as ENUM('first', 'second', 'third');
            CREATE TYPE hello as ENUM('hi', 'hello');
        "#;
        let mut parser = Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        let root = parser.parse(source, None).unwrap();
        parse_create_type_enum(source, &root.root_node());
    }

    #[test]
    fn test_create_composite_type() {
        let source = r#"
            CREATE TYPE mood as ENUM('first', 'second', 'third');
            CREATE TYPE hello as ENUM('hi', 'hello');

            CREATE TYPE typename AS (
                r double precision,
                i integer ARRAY,
                k integer[],
                valami varchar
            );
        "#;
        let mut parser = Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        let root = parser.parse(source, None).unwrap();
        parse_create_type_composite(source, &root.root_node());

        panic!();
    }
}
