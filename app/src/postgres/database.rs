use itertools::Itertools;
use std::fmt::Write;
use uuid::Uuid;

use super::types::{CompositeField, Type};
use crate::cassandra::database::ColumnDefinition as CColumnDefinition;
use crate::cassandra::database::Table as CTable;
use crate::query::Query;

#[derive(Debug, Clone)]
pub struct Schema {
    name: String,
    tables: Vec<Table>,
    composites: Vec<CompositeType>,
    enums: Vec<Enum>,
}

#[derive(Debug, Clone)]
pub struct Enum {
    name: String,
    values: Vec<String>,
}

impl Enum {
    pub fn new(name: String, values: Vec<String>) -> Self {
        Self { name, values }
    }
    pub fn name(&self) -> &str {
        &self.name
    }
}

impl Schema {
    pub fn new(name: String) -> Self {
        Self {
            name,
            tables: Vec::new(),
            composites: Vec::new(),
            enums: Vec::new(),
        }
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn tables(&self) -> &Vec<Table> {
        &self.tables
    }
    pub fn add_enum(&mut self, enum_: Enum) {
        self.enums.push(enum_);
    }
    pub fn add_table(&mut self, table: Table) {
        self.tables.push(table);
    }
    pub fn tables_mut(&mut self) -> &mut Vec<Table> {
        &mut self.tables
    }
    pub fn composites(&self) -> &Vec<CompositeType> {
        &self.composites
    }
    pub fn add_composite(&mut self, composite: CompositeType) {
        self.composites.push(composite);
    }
    pub fn enums(&self) -> &Vec<Enum> {
        &self.enums
    }

    fn query_string(&self) -> String {
        let mut query_string = String::new();
        let query_ref = &mut query_string;
        write!(query_ref, "CREATE SCHEMA {};", self.name).unwrap();
        writeln!(query_ref).unwrap();

        for table in self.tables().iter() {
            write!(query_ref, "{}", Self::query_string_table(table)).unwrap();
        }

        query_string
    }

    fn query_string_table(table: &Table) -> String {
        let mut query_string = String::new();
        let query_ref = &mut query_string;

        writeln!(query_ref, "CREATE TABLE {} (", table.name).unwrap();
        for (i, column) in table.columns.iter().enumerate() {
            let nullable = if column.nullable { "" } else { "not null" };
            if i == table.columns.len() - 1 {
                writeln!(
                    query_ref,
                    "\t{} {} {}",
                    column.name, column.r#type, nullable
                )
                .unwrap();
            } else {
                writeln!(
                    query_ref,
                    "\t{} {} {},",
                    column.name, column.r#type, nullable
                )
                .unwrap();
            }
        }
        write!(query_ref, ");").unwrap();
        writeln!(query_ref).unwrap();

        writeln!(
            query_ref,
            "ALTER TABLE {} ADD PRIMARY KEY ({});",
            table.name,
            table.primary_keys.iter().join(", ")
        )
        .unwrap();

        // TODO: Write foreign keys.
        // might need fixing somewhere else to get the optional parts (schema, ref schema...)
        for foreign_key in table.foreign_keys.iter() {
            write!(
                query_ref,
                "ALTER TABLE {}.{} ADD CONSTRAINT {}_{}_fkey FOREIGN KEY ({}) REFERENCES {}.{}({}) ",
                foreign_key.schema,
                table.name,
                table.name,
                foreign_key.column.iter().join("_"),
                foreign_key.column.iter().join(", "),
                foreign_key.referenced_schema,
                foreign_key.references_table,
                foreign_key.references_column.iter().join(", "),
            )
            .unwrap();
            if let Some(action) = foreign_key.on_update {
                write!(query_ref, "ON UPDATE {}", action).unwrap();
            }
            if let Some(action) = foreign_key.on_delete {
                write!(query_ref, "ON DELETE {}", action).unwrap();
            }
            writeln!(query_ref, ";").unwrap();
        }

        query_string
    }
}

impl Query for Schema {
    fn to_query_string(&self) -> String {
        self.query_string()
    }
}

#[derive(Debug, Clone)]
pub struct Table {
    name: String,
    columns: Vec<ColumnDefinition>,
    primary_keys: Vec<String>,
    foreign_keys: Vec<ForeignKey>,
    uuid: Uuid,
}

impl Table {
    pub fn new(name: String) -> Self {
        Self {
            name,
            columns: Vec::new(),
            primary_keys: Vec::new(),
            foreign_keys: Vec::new(),
            uuid: Uuid::new_v4(),
        }
    }

    pub fn from_cassandra_table(cassandra_table: &CTable) -> Self {
        Self {
            name: cassandra_table.name().to_string(),
            columns: Vec::new(),
            primary_keys: Vec::new(),
            foreign_keys: Vec::new(),
            uuid: cassandra_table.uuid(),
        }
    }

    pub fn retrieve_column(&self, name: &str) -> Option<&ColumnDefinition> {
        self.columns.iter().find(|column| column.name == name)
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn columns(&self) -> &Vec<ColumnDefinition> {
        &self.columns
    }
    pub fn columns_mut(&mut self) -> &mut Vec<ColumnDefinition> {
        &mut self.columns
    }
    pub fn add_column(&mut self, column: ColumnDefinition) {
        self.columns.push(column);
    }
    pub fn primary_keys(&self) -> &Vec<String> {
        &self.primary_keys
    }
    pub fn primary_keys_mut(&mut self) -> &mut Vec<String> {
        &mut self.primary_keys
    }
    pub fn add_primary_key(&mut self, key: String) {
        self.primary_keys.push(key);
    }
    pub fn foreign_keys(&self) -> &Vec<ForeignKey> {
        &self.foreign_keys
    }
    pub fn add_foreign_key(&mut self, fk: ForeignKey) {
        self.foreign_keys.push(fk);
    }
    pub fn uuid(&self) -> Uuid {
        self.uuid
    }
    pub fn set_uuid(&mut self, uuid: Uuid) {
        self.uuid = uuid
    }
    pub fn set_uuid_from_parent(&mut self, ctable: &CTable) {
        self.uuid = ctable.uuid();
    }
}

#[derive(Debug, Clone)]
pub struct ColumnDefinition {
    name: String,
    r#type: Type,
    nullable: bool,
    uuid: Uuid,
}

impl ColumnDefinition {
    pub fn new(name: String, type_: Type) -> Self {
        Self {
            name,
            r#type: type_,
            nullable: false,
            uuid: Uuid::new_v4(),
        }
    }

    pub fn from_cassandra_coldef(cassandra_coldef: &CColumnDefinition, type_: Type) -> Self {
        Self {
            name: cassandra_coldef.name().to_string(),
            r#type: type_,
            nullable: false,
            uuid: cassandra_coldef.uuid(),
        }
    }

    pub fn set_uuid(&mut self, uuid: Uuid) {
        self.uuid = uuid;
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn r#type(&self) -> &Type {
        &self.r#type
    }
    pub fn uuid(&self) -> Uuid {
        self.uuid
    }
}

#[derive(Debug, Clone)]
pub struct ForeignKey {
    schema: String,
    referenced_schema: String,
    column: Vec<String>,
    references_table: String,
    references_column: Vec<String>,
    on_delete: Option<Action>,
    on_update: Option<Action>,
}

impl ForeignKey {
    pub fn new(
        schema: String,
        referenced_schema: String,
        column: Vec<String>,
        references_table: String,
        references_column: Vec<String>,
    ) -> Self {
        Self {
            schema,
            referenced_schema,
            column,
            references_table,
            references_column,
            on_delete: None,
            on_update: None,
        }
    }

    pub fn referenced_table(&self) -> &str {
        &self.references_table
    }
}

#[derive(Debug, Clone, Copy)]
pub enum Action {
    Cascade,
    SetNull,
    Restrict,
}

impl std::fmt::Display for Action {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Action::Cascade => write!(f, "CASCADE"),
            Action::SetNull => write!(f, "SET NULL"),
            Action::Restrict => write!(f, "RESTRICT"),
        }
    }
}

#[derive(Debug, Clone)]
pub struct CompositeType {
    name: String,
    fields: Vec<CompositeField>,
}

impl CompositeType {
    pub fn new(name: String) -> Self {
        Self {
            name,
            fields: Vec::new(),
        }
    }
    pub fn add_field(&mut self, field: CompositeField) {
        self.fields.push(field);
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn fields(&self) -> &Vec<CompositeField> {
        &self.fields
    }
}
