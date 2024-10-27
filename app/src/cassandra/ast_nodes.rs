pub struct AstNode;

impl AstNode {
    pub const SOURCE_FILE: &str = "source_file";
    pub const CREATE_TYPE: &str = "create_type";
    pub const TYPED_NAME: &str = "typed_name";
    pub const DATA_TYPE: &str = "data_type";
    pub const CQL_TYPE: &str = "cql_type";
    pub const TYPE_NAME: &str = "type_name";
    pub const CREATE_KEYSPACE: &str = "create_keyspace";
    pub const KEYSPACE_NAME: &str = "keyspace_name";
    pub const REPLICATION_LIST: &str = "replication_list";
    pub const REPLICATION_LIST_ITEM: &str = "replication_list_item";
    pub const DURABLE_WRITES: &str = "durable_writes";
    pub const CREATE_TABLE: &str = "create_table";
    pub const TABLE_NAME: &str = "table_name";
    pub const COLUMN_DEFINITION_LIST: &str = "column_definition_list";
    pub const COLUMN_DEFINITION: &str = "column_definition";
    pub const NATIVE_TYPE: &str = "native_type";
    pub const COLLECTION_TYPE: &str = "collection_type";
    pub const TUPLE_TYPE: &str = "tuple_type";
    pub const FROZEN_TYPE: &str = "frozen_type";
    pub const USER_DEFINED_TYPE: &str = "user_defined_type";
}

pub struct AstCollectionNode;

impl AstCollectionNode {
    pub const SET: &str = "set";
    pub const LIST: &str = "list";
    pub const MAP: &str = "map";
}
