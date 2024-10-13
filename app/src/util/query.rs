use tree_sitter::{Node, Query, QueryCursor, QueryMatches, TextProvider};

pub fn query_matches<'query, 'cursor: 'query, 'tree, T, I>(
    query: &'query Query,
    text_provider: T,
    node: Node<'tree>,
    cursor: &'cursor mut QueryCursor,
) -> QueryMatches<'query, 'tree, T, I>
where
    I: AsRef<[u8]>,
    T: TextProvider<I>,
{
    cursor.matches(query, node, text_provider)
}
