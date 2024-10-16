use tree_sitter::{Node, Query, QueryCursor, QueryMatches};

pub fn query_matches<'query, 'cursor: 'query, 'tree, 'text: 'cursor>(
    query: &'query Query,
    text: &'text str,
    node: Node<'tree>,
    cursor: &'cursor mut QueryCursor,
) -> QueryMatches<'query, 'tree, &'text [u8], &'text [u8]> {
    cursor.matches(query, node, &text.as_bytes()[..])
}
