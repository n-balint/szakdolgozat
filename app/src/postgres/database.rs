use uuid::Uuid;

use super::types::{CompositeField, Type};
use crate::cassandra::database::ColumnDefinition as CColumnDefinition;
use crate::cassandra::database::Table as CTable;

#[derive(Debug, Clone)]
pub struct Schema {
    name: String,
    tables: Vec<Table>,
    composites: Vec<CompositeType>,
}

impl Schema {
    pub fn new(name: String) -> Self {
        Self {
            name,
            tables: Vec::new(),
            composites: Vec::new(),
        }
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn tables(&self) -> &Vec<Table> {
        &self.tables
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
}

#[derive(Debug, Clone)]
pub struct Table {
    name: String,
    columns: Vec<ColumnDefinition>,
    primary_key: Vec<String>,
    foreign_keys: Vec<ForeignKey>,
    uuid: Uuid,
}

impl Table {
    pub fn new(name: String) -> Self {
        Self {
            name,
            columns: Vec::new(),
            primary_key: Vec::new(),
            foreign_keys: Vec::new(),
            uuid: Uuid::new_v4(),
        }
    }

    pub fn from_cassandra_table(cassandra_table: &CTable) -> Self {
        Self {
            name: cassandra_table.name().to_string(),
            columns: Vec::new(),
            primary_key: Vec::new(),
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
    pub fn add_column(&mut self, column: ColumnDefinition) {
        self.columns.push(column);
    }
    pub fn remove_column(&mut self, name: &str) {
        match self.columns.iter().position(|column| column.name == name) {
            Some(index) => {
                self.columns.swap_remove(index);
            }
            None => (),
        }
    }
    pub fn primary_keys(&self) -> &Vec<String> {
        &self.primary_key
    }
    pub fn add_primary_key(&mut self, key: String) {
        self.primary_key.push(key);
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
    default: Option<String>,
    unique: bool,
    uuid: Uuid,
}

impl ColumnDefinition {
    pub fn new(name: String, type_: Type) -> Self {
        Self {
            name,
            r#type: type_,
            nullable: false,
            default: None,
            unique: false,
            uuid: Uuid::new_v4(),
        }
    }

    pub fn from_cassandra_coldef(cassandra_coldef: &CColumnDefinition, type_: Type) -> Self {
        Self {
            name: cassandra_coldef.name().to_string(),
            r#type: type_,
            nullable: false,
            default: None,
            unique: false,
            uuid: cassandra_coldef.uuid(),
        }
    }

    pub fn set_unique(&mut self, unique: bool) {
        self.unique = unique;
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
    column: Vec<String>,
    references_table: String,
    references_column: Vec<String>,
    on_delete: Option<OnDelete>,
}

impl ForeignKey {
    pub fn new(
        column: Vec<String>,
        references_table: String,
        references_column: Vec<String>,
    ) -> Self {
        Self {
            column,
            references_table,
            references_column,
            on_delete: None,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub enum OnDelete {
    Cascade,
    SetNull,
    Restrict,
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
}
