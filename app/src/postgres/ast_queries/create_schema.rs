use anyhow::anyhow;
use tree_sitter::{Node, Query, QueryCursor};

pub fn parse_create_schema<'a>(source: &'a str, node: &Node) -> Result<&'a str, anyhow::Error> {
    let query_str = "(statement (create_schema (identifier) @schema_name))";
    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());
    let mut schemas = Vec::new();
    for (capture, _idx) in captures {
        for m in capture.captures {
            schemas.push(&source[m.node.byte_range()]);
        }
    }
    if let Some(schema_name) = schemas.first() {
        Ok(schema_name)
    } else {
        Err(anyhow!("Schema declaration not found."))
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use tree_sitter::Parser;

    #[test]
    fn test_create_schema_capture() {
        let source = r#"
CREATE SCHEMA kepalbumok;

ALTER SCHEMA kepalbumok OWNER TO example;

SET default_tablespace = '';

SET default_table_access_method = heap;

CREATE TABLE kepalbumok.ertekeles (
    ertekeles_id integer NOT NULL,
    pontszam smallint NOT NULL,
    email character varying(255) NOT NULL,
    kep_id integer NOT NULL,
    CONSTRAINT pontszam_c CHECK ((pontszam = ANY (ARRAY['-1'::integer, 1])))
);

        "#;

        let mut parser = Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        let root = parser.parse(source, None).unwrap();
        assert_eq!(
            parse_create_schema(source, &root.root_node()).unwrap(),
            "kepalbumok"
        );
    }
}
