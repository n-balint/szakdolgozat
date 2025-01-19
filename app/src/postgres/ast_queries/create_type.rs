use std::collections::{HashMap, HashSet};

use tree_sitter::{Node, Query, QueryCursor};

fn parse_create_type_enum(source: &str, node: &Node) {
    let query_str = r#"
    "#;

    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    let mut seen = HashSet::new();

    for (capture, _idx) in captures {
        let mut placeholder = None;

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            match capture_name {
                "placeholder" => placeholder = Some(value),
                _ => panic!("Found unknown capture target. Check the query."),
            }
        }

        if let Some(placeholder) = placeholder {
            let entry = placeholder;
            if !seen.contains(&entry) {
                seen.insert(entry);
            }
        }
    }
}

fn parse_create_type_composite(source: &str, node: &Node) {
    let query_str = r#"
    "#;

    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    let mut seen = HashSet::new();

    for (capture, _idx) in captures {
        let mut placeholder = None;

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            match capture_name {
                "placeholder" => placeholder = Some(value),
                _ => panic!("Found unknown capture target. Check the query."),
            }
        }

        if let Some(placeholder) = placeholder {
            let entry = placeholder;
            if !seen.contains(&entry) {
                seen.insert(entry);
            }
        }
    }
}
