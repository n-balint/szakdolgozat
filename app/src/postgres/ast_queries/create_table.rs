use std::collections::HashSet;

use anyhow::anyhow;
use tree_sitter::{Node, Query, QueryCursor};

fn parse_create_table<'a>(source: &'a str, node: &Node) -> Result<&'a str, anyhow::Error> {
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
    let mut schema = Vec::new();
    let mut table = Vec::new();
    let mut name = Vec::new();
    let mut type_ = Vec::new();
    let mut seen = HashSet::new();
    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());
    for (capture, _idx) in captures {
        for (i, m) in capture.captures.iter().enumerate() {
            let inner = &source[m.node.byte_range()];
            match i {
                0 => schema.push(inner),
                1 => table.push(inner),
                2 => name.push(inner),
                3 => type_.push(inner),
                _ => panic!(),
            };
        }
    }
    for i in 0..schema.len() {
        let item = (schema[i], table[i], name[i], type_[i]);
        if seen.insert(item) {
            println!("{}.{} {} | {}", schema[i], table[i], name[i], type_[i]);
        }
    }
    Ok("")
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
