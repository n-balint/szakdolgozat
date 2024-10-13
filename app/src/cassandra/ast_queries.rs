use tree_sitter::{Node, Query, QueryCursor};

use crate::util::query::query_matches;

pub fn keyspace_query(source: &str, node: &Node<'_>) {
    let query_sexp = "(create_keyspace
                              (keyspace_name) @keyspace_name
                              (replication_list
                                (replication_list_item) @replication_list_item)
                              (durable_writes)? @durable_writes)";
    let query =
        Query::new(&tree_sitter_cql::language(), query_sexp).expect("Failed to load cql parser.");
    let mut cursor = QueryCursor::new();
    let matches = query_matches(&query, source[..].as_bytes(), *node, &mut cursor);
    let res: Vec<_> = matches.into_iter().collect();
    println!("{:#?}", res);
}
