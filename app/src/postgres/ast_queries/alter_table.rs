use std::collections::{HashMap, HashSet};

use tree_sitter::{Node, Query, QueryCursor};

fn parse_alter_table_primary_key(source: &str, node: &Node) {
    let query_str = r#"
        (statement
          (alter_table
            (object_reference
              schema: (identifier)@schema_name
              name: (identifier)@table_name)
            (add_constraint
              (constraint
                (keyword_primary)
                (keyword_key)
                (ordered_columns
                  (column
                    name: (identifier)@column_name))))))
    "#;

    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    let mut table_keys: HashMap<(String, String), Vec<String>> = HashMap::new();
    let mut seen = HashSet::new();

    for (capture, _idx) in captures {
        let mut schema_name = None;
        let mut table_name = None;
        let mut column_name = None;

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            match capture_name {
                "schema_name" => schema_name = Some(value),
                "table_name" => table_name = Some(value),
                "column_name" => column_name = Some(value),
                _ => panic!("Found unknown capture target. Check the query."),
            }
        }

        if let (Some(schema), Some(table), Some(column)) = (schema_name, table_name, column_name) {
            let key = (schema, table);
            if !seen.contains(&(key.clone(), column.clone())) {
                table_keys
                    .entry(key.clone())
                    .or_default()
                    .push(column.clone());
                seen.insert((key, column));
            }
        }
    }
}

fn parse_alter_table_foreign_key(source: &str, node: &Node) {
    let query_str = r#"
        (statement
          (alter_table
            (object_reference
             schema: (identifier)@schema_name
             name: (identifier)@table_name)
            (add_constraint
              (constraint
                (keyword_foreign)
                (keyword_key)
                (ordered_columns
                  (column
                   name: (identifier)@column_name))
                (object_reference
                 schema: (identifier)@ref_schema
                 name: (identifier)@ref_table)
                (identifier)@ref_column))))
    "#;

    let query = Query::new(&tree_sitter_sequel::language(), query_str).unwrap();
    let mut query_cursor = QueryCursor::new();
    let captures = query_cursor.captures(&query, *node, source.as_bytes());

    let mut seen = HashSet::new();

    for (capture, _idx) in captures {
        let mut schema_name = None;
        let mut table_name = None;
        let mut column_name = None;
        let mut ref_schema = None;
        let mut ref_table = None;
        let mut ref_column = None;

        for m in capture.captures.iter() {
            let capture_name = query.capture_names()[m.index as usize];
            let value = source[m.node.byte_range()].to_string();

            match capture_name {
                "schema_name" => schema_name = Some(value),
                "table_name" => table_name = Some(value),
                "column_name" => column_name = Some(value),
                "ref_schema" => ref_schema = Some(value),
                "ref_table" => ref_table = Some(value),
                "ref_column" => ref_column = Some(value),
                _ => panic!("Found unknown capture target. Check the query."),
            }
        }

        if let (
            Some(schema),
            Some(table),
            Some(column),
            Some(ref_schema),
            Some(ref_table),
            Some(ref_column),
        ) = (
            schema_name,
            table_name,
            column_name,
            ref_schema,
            ref_table,
            ref_column,
        ) {
            let entry = (schema, table, column, ref_schema, ref_table, ref_column);
            if !seen.contains(&entry) {
                seen.insert(entry);
            }
        }
    }

    type TableColumnMapping =
        HashMap<(String, String, String, String), (HashSet<String>, HashSet<String>)>;

    let mut column_mapping: TableColumnMapping = HashMap::new();

    for (schema, table, column, ref_schema, ref_table, ref_column) in seen {
        let tuple = column_mapping
            .entry((schema, table, ref_schema, ref_table))
            .or_default();
        tuple.0.insert(column);
        tuple.1.insert(ref_column);
    }

    println!("{:#?}", column_mapping);
}

#[cfg(test)]
mod test {
    use tree_sitter::Parser;

    use super::*;
    #[test]
    fn test_primary_keys() {
        let source = r#"
ALTER TABLE ONLY kepalbumok.ertekeles
    ADD CONSTRAINT ertekeles_pkey PRIMARY KEY (ertekeles_id);



ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_nev_key UNIQUE (nev);



ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_pkey PRIMARY KEY (email);



ALTER TABLE ONLY kepalbumok.helyszin
    ADD CONSTRAINT helyszin_pkey PRIMARY KEY (megye, telepules);



ALTER TABLE ONLY kepalbumok.kategoria
    ADD CONSTRAINT kategoria_nev_key UNIQUE (nev);



ALTER TABLE ONLY kepalbumok.kategoria
    ADD CONSTRAINT kategoria_pkey PRIMARY KEY (kategoria_id);
        "#;
        let mut parser = Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        let root = parser.parse(source, None).unwrap();
        parse_alter_table_primary_key(source, &root.root_node());
        // TODO: Write test.
    }
    #[test]
    fn test_foreign_keys() {
        let source = r#"
ALTER TABLE ONLY kepalbumok.ertekeles
    ADD CONSTRAINT ertekeles_email_fkey FOREIGN KEY (email) REFERENCES kepalbumok.felhasznalo(email) ON DELETE CASCADE;



ALTER TABLE ONLY kepalbumok.ertekeles
    ADD CONSTRAINT ertekeles_kep_id_fkey FOREIGN KEY (kep_id) REFERENCES kepalbumok.kep(kep_id) ON DELETE CASCADE;



ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_kategoria_id_fkey FOREIGN KEY (kategoria_id) REFERENCES kepalbumok.kategoria(kategoria_id) ON DELETE SET NULL;



ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_megye_telepules_fkey FOREIGN KEY (megye, telepules) REFERENCES kepalbumok.helyszin(megye, telepules) ON DELETE SET NULL;



ALTER TABLE ONLY kepalbumok.kep
    ADD CONSTRAINT kep_email_fkey FOREIGN KEY (email) REFERENCES kepalbumok.felhasznalo(email) ON DELETE SET NULL;
        "#;
        let mut parser = Parser::new();
        parser
            .set_language(&tree_sitter_sequel::language())
            .unwrap();
        let root = parser.parse(source, None).unwrap();
        parse_alter_table_foreign_key(source, &root.root_node());
        // TODO: Write test.
    }
}
