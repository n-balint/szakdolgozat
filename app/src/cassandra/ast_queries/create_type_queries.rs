use tree_sitter::TreeCursor;

use crate::cassandra::database::Udt;

pub fn udt_query(cursor: &mut TreeCursor<'_>, source: &str) -> Result<Vec<Udt>, ()> {
    let mut udts = Vec::new();

    debug_assert_eq!(cursor.node().kind(), "source_file");
    cursor.goto_first_child();
    loop {
        if !cursor.goto_next_sibling() {
            break;
        }
        if cursor.node().kind() == "create_type" {
            let keyspace_and_name = query_type_name_and_keyspace(cursor, source)?;
            let split = keyspace_and_name.split('.').collect::<Vec<_>>();
            if split.get(1).is_none() {
                return Err(());
            }
            let udt = Udt::new(split[1]);
        }
    }

    Ok(udts)
}

fn query_type_name_and_keyspace(cursor: &mut TreeCursor<'_>, source: &str) -> Result<String, ()> {
    debug_assert_eq!(cursor.node().kind(), "create_type");
    let original_cursor = cursor.clone();
    cursor.goto_first_child();
    loop {
        if cursor.node().kind() == "type_name" {
            let name = Ok(source[cursor.node().byte_range()].to_string());
            return name;
            cursor.reset_to(&original_cursor);
            return name;
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Err(())
}
