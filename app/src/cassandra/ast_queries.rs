use super::database::Keyspace;

pub mod create_type_queries;
pub mod keyspace_queries;
pub mod table_queries;

use create_type_queries::udt_query;
use keyspace_queries::keyspace_query;
use table_queries::table_query;
use tree_sitter::Tree;

pub fn parse_database(source: &str, tree: &Tree) -> Result<Keyspace, ()> {
    let mut keyspace = keyspace_query(source, tree)?;
    let tables = table_query(source, tree)?;
    keyspace.set_tables(tables);
    let udts = udt_query(source, tree)?;
    keyspace.set_udts(udts);

    Ok(keyspace)
}
