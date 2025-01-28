use alter_table::{parse_alter_table_foreign_key, parse_alter_table_primary_key};
use create_schema::parse_create_schema;
use create_table::parse_create_table;
use create_type::{parse_create_type_composite, parse_create_type_enum};
use itertools::Itertools;
use tree_sitter::Node;

use super::{
    database::{ColumnDefinition, CompositeType, Enum, ForeignKey, Schema, Table},
    types::{CompositeField, PrimitiveType, Type},
};

pub mod alter_table;
pub mod create_schema;
pub mod create_table;
pub mod create_type;

pub(crate) fn parse_postgres_dump(source: &str, node: &Node<'_>) -> Result<Schema, anyhow::Error> {
    let mut schema = parse_schema(source, node)?;
    parse_enums(source, node, &mut schema);
    parse_composites(source, node, &mut schema);
    parse_tables(source, node, &mut schema);
    associate_primary_keys(source, node, &mut schema);
    associate_foreign_keys(source, node, &mut schema);
    Ok(schema)
}

pub fn parse_schema(source: &str, node: &Node<'_>) -> Result<Schema, anyhow::Error> {
    let name = parse_create_schema(source, node)?;
    let schema = Schema::new(name.to_string());
    Ok(schema)
}

pub fn parse_tables(source: &str, node: &Node<'_>, schema: &mut Schema) {
    let table_map = parse_create_table(source, node);

    for (table_name, column_details) in table_map.into_iter() {
        let mut table = Table::new(table_name);
        for (name, type_) in column_details.into_iter() {
            let parsed_type = match type_.as_str().try_into() {
                Ok(simple_type) => simple_type,
                Err(name) => {
                    if schema.enums().iter().any(|e| e.name() == name) {
                        Type::Enum(name)
                    } else {
                        Type::Composite(name)
                    }
                }
            };
            table.add_column(ColumnDefinition::new(name, parsed_type));
        }
        schema.add_table(table);
    }
}

pub fn associate_primary_keys(source: &str, node: &Node<'_>, schema: &mut Schema) {
    let key_mapping = parse_alter_table_primary_key(source, node);
    for ((schema_name, table_name), columns) in key_mapping.into_iter() {
        if schema_name == schema.name() {
            if let Some(table) = schema
                .tables_mut()
                .iter_mut()
                .find(|t| t.name() == table_name)
            {
                columns
                    .into_iter()
                    .for_each(|column_name| table.add_primary_key(column_name));
            }
        }
    }
}

pub fn associate_foreign_keys(source: &str, node: &Node<'_>, schema: &mut Schema) {
    let foreign_key_mapping = parse_alter_table_foreign_key(source, node);

    for (
        (schema_name, table_name, ref_schema_name, ref_table_name),
        (column_name, ref_column_name),
    ) in foreign_key_mapping.into_iter()
    {
        if schema_name == ref_schema_name && schema_name == schema.name() {
            if let Some(table) = schema
                .tables_mut()
                .iter_mut()
                .find(|t| t.name() == table_name)
            {
                let column_name = column_name.into_iter().collect_vec();
                let ref_column_name = ref_column_name.into_iter().collect_vec();
                table.add_foreign_key(ForeignKey::new(
                    schema_name,
                    ref_schema_name,
                    column_name,
                    ref_table_name,
                    ref_column_name,
                ));
            }
        }
    }
}

pub fn parse_composites(source: &str, node: &Node<'_>, schema: &mut Schema) {
    let composite_map = parse_create_type_composite(source, node);
    for (composite_name, details) in composite_map.into_iter() {
        let mut composite_type = CompositeType::new(composite_name);
        for (name, type_, array) in details.into_iter() {
            let field;
            if let Ok(parsed_type) = type_.as_str().try_into() {
                if array.is_empty() {
                    field = CompositeField::new(name, parsed_type);
                    composite_type.add_field(field);
                } else if let Type::Simple(parsed_type) = parsed_type {
                    field = CompositeField::new(name, Type::Array(parsed_type));
                    composite_type.add_field(field);
                }
            }
        }
        schema.add_composite(composite_type);
    }
}

pub fn parse_enums(source: &str, node: &Node<'_>, schema: &mut Schema) {
    let enums = parse_create_type_enum(source, node);

    for (name, values) in enums.into_iter() {
        schema.add_enum(Enum::new(name, values));
    }
}
