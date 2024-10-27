use tree_sitter::TreeCursor;

pub fn move_to_node(cursor: &mut TreeCursor<'_>, target: &str) -> Result<(), ()> {
    loop {
        if cursor.node().kind() == target {
            return Ok(());
        }
        if !cursor.goto_next_sibling() {
            break;
        }
    }
    Err(())
}

pub fn node_text<'a>(cursor: &TreeCursor<'_>, source: &'a str) -> &'a str {
    &source[cursor.node().byte_range()]
}
