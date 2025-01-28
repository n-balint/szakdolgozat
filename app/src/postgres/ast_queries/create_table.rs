use std::collections::{HashMap, HashSet};

use tree_sitter::{Node, Query, QueryCursor};

pub fn parse_create_table(source: &str, node: &Node) -> HashMap<String, Vec<(String, String)>> {
    let query_str = r#"
    (statement
      (create_table
        (object_reference
          schema: (identifier)@schema_name
          name: (identifier)@table_name)
        (column_definitions
          (column_definition
            name: (identifier)@column_name
            type: (_)@type))))"#;
    let mut seen = HashSet::new();
    let mut grouped_by_table: HashMap<String, Vec<_>> = HashMap::new();
    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    for (capture, _idx) in captures {
        let mut schema_name = None;
        let mut table_name = None;
        let mut column_name = None;
        let mut type_ = None;

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            match capture_name {
                "schema_name" => schema_name = Some(value),
                "table_name" => table_name = Some(value),
                "column_name" => column_name = Some(value),
                "type" => {
                    type_ = Some(
                        value
                            .trim_end_matches(|c: char| c == '(' || c == ')' || c.is_ascii_digit())
                            .to_string(),
                    )
                }
                _ => panic!("Found unknown capture target."),
            }
        }

        if let (Some(schema_name), Some(table_name), Some(column_name), Some(type_)) =
            (schema_name, table_name, column_name, type_)
        {
            let entry = (schema_name, table_name, column_name, type_);
            if !seen.contains(&entry) {
                seen.insert(entry);
            }
        }
    }

    for (_schema_name, table_name, column_name, type_) in seen {
        grouped_by_table
            .entry(table_name)
            .or_default()
            .push((column_name, type_));
    }

    grouped_by_table
}

#[cfg(test)]
mod test {
    use tree_sitter::Parser;

    use super::*;

    #[test]
    fn test_create_table_parser() {
        let source = r#"
CREATE TABLE kepalbumok.megjegyzes (
    megjegyzes_id integer NOT NULL,
    datum timestamp without time zone NOT NULL,
    tartalom character varying(511) NOT NULL,
    email character varying(255) NOT NULL,
    kep_id integer NOT NULL
);

CREATE TABLE kepalbumok.kep (
    kep_id integer NOT NULL,
    cim character varying(255) NOT NULL,
    eleresi_ut character(36) NOT NULL,
    email character varying(255) NOT NULL,
    telepules character varying(255) NOT NULL,
    megye character varying(255) NOT NULL,
    datum timestamp without time zone NOT NULL,
    palyazat_id integer
);
        "#;
        let mut parser = Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        let root = parser.parse(source, None).unwrap();

        // TODO: Write test case.
    }
}
