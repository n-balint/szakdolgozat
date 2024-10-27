use super::types::{CompositeField, PrimitiveType, Type};

#[derive(Debug, Clone)]
pub struct Schema {
    name: String,
    tables: Vec<Table>,
    enums: Vec<Enum>,
    domains: Vec<Domain>,
    composites: Vec<CompositeType>,
}

#[derive(Debug, Clone)]
pub struct Table {
    name: String,
    columns: Vec<ColumnDefinition>,
    primary_key: Vec<String>,
    foreign_keys: Vec<ForeignKey>,
}

#[derive(Debug, Clone)]
pub struct ColumnDefinition {
    name: String,
    r#type: Type,
    nullable: bool,
    default: Option<String>,
    unique: bool,
}

#[derive(Debug, Clone)]
pub struct ForeignKey {
    column: String,
    references_table: String,
    references_column: String,
    on_delete: Option<OnDelete>,
}

#[derive(Debug, Clone, Copy)]
pub enum OnDelete {
    Cascade,
    SetNull,
    Restrict,
}

#[derive(Debug, Clone)]
pub struct Enum {
    name: String,
    values: Vec<String>,
}

#[derive(Debug, Clone)]
pub struct Domain {
    name: String,
    base_type: PrimitiveType,
    constraints: Vec<DomainConstraint>,
}

#[derive(Debug, Clone)]
pub enum DomainConstraint {
    NotNull,
    Unique,
    Check(String),
}

#[derive(Debug, Clone)]
pub struct CompositeType {
    name: String,
    fields: Vec<CompositeField>,
}
