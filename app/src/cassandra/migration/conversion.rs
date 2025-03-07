use std::{collections::HashMap, error::Error, path::Path};

use csv::{ReaderBuilder, WriterBuilder};

use crate::{
    cassandra::{
        database::{ColumnDefinition as CassandraColumn, Keyspace, Table as CTable},
        types::{CollectionType, Type as CType},
    },
    postgres::{
        self,
        database::{ColumnDefinition as PostgresColumn, ForeignKey, Schema, Table as PTable},
        types::{CompositeField, PrimitiveType as PostgresPrimitive, Type as PostgresType},
    },
};

pub(crate) fn convert_ir_to_final_export(
    old_schema: &Schema,
    normalized_schema: &Schema,
    mir_folder: &Path,
    export_folder: &Path,
) -> Result<(), Box<dyn Error>> {
    for table in normalized_schema.tables().iter() {
        let mut new_table_writer = WriterBuilder::new()
            .escape(b'\"')
            .quote(b'\"')
            .from_path(export_folder.join(format!("{}.csv", table.name())))?;

        let header = table.columns().iter().map(|c| c.name());
        new_table_writer.write_record(header)?;

        let old_table = old_schema
            .tables()
            .iter()
            .find(|t| t.uuid() == table.uuid())
            .expect("Logic error.");

        let old_table_path = mir_folder.join(format!("{}.IR", old_table.name()));

        let mut reader = ReaderBuilder::new()
            .escape(Some(b'\"'))
            .quote(b'\"')
            .has_headers(true)
            .from_path(old_table_path)?;

        let lookup_map = reader
            .headers()?
            .iter()
            .enumerate()
            .map(|(x, y)| (y.to_string(), x))
            .collect::<HashMap<_, _>>();

        for record in reader.records() {
            let record = record?;
            let mut new_row = Vec::with_capacity(table.columns().len());
            for column in table.columns().iter() {
                let old_column = old_table
                    .columns()
                    .iter()
                    .find(|c| c.uuid() == column.uuid())
                    .expect("Logic error");

                let column_name = old_column.name();
                println!("{column_name}");
                println!("{:#?}", lookup_map);
                let column_index = lookup_map[column_name];

                let value = &record[column_index];
                new_row.push(value);
            }
            new_table_writer.write_record(&new_row)?;
        }
        new_table_writer.flush()?;
    }
    Ok(())
}

pub(crate) fn convert_keyspace_to_schema(keyspace: &Keyspace) -> Result<Schema, ()> {
    let mut schema = Schema::new(keyspace.name().to_string());
    convert_tables(&mut schema, keyspace)?;

    Ok(schema)
}

pub fn convert_tables(schema: &mut Schema, keyspace: &Keyspace) -> Result<(), ()> {
    let cassandra_tables = keyspace.tables();

    for table in cassandra_tables.iter() {
        let mut ptable = PTable::new(table.name().to_string());
        ptable.set_uuid_from_parent(table);

        let keys = table.primary_keys();
        keys.iter()
            .for_each(|key| ptable.add_primary_key(key.name().to_string()));

        let cassandra_columns = table.columns();

        for column in cassandra_columns.iter() {
            convert_column_definition(keyspace, schema, &mut ptable, column)?;
        }

        schema.add_table(ptable);
    }
    Ok(())
}

fn convert_column_definition(
    keyspace: &Keyspace,
    schema: &mut Schema,
    postgres_table: &mut PTable,
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    match cassandra_column.r#type() {
        CType::Primitive(cassandra_primitive) => {
            let mut postgres_column = PostgresColumn::new(
                cassandra_column.name().to_string(),
                PostgresType::Simple((*cassandra_primitive).into()),
            );
            postgres_column.set_uuid(cassandra_column.uuid());
            postgres_table.add_column(postgres_column);
        }
        CType::Collection { r#type, .. } => {
            convert_collection(keyspace, schema, postgres_table, r#type, cassandra_column)?
        }
        CType::Tuple(types) => {
            convert_tuple(keyspace, schema, postgres_table, types, cassandra_column)?
        }
        CType::Udt {
            name,
            keyspace: keyspace_name,
            ..
        } => convert_udt(
            keyspace,
            schema,
            postgres_table,
            name,
            keyspace_name,
            cassandra_column,
        )?,
    }
    Ok(())
}

fn convert_udt(
    keyspace: &Keyspace,
    schema: &mut Schema,
    postgres_table: &mut PTable,
    name: &str,
    keyspace_name: &str,
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    let udt_definition = keyspace.find_udt_definition(name).ok_or(())?;
    let mut udt_table = PTable::new(format!(
        "{}_{}",
        cassandra_column.name(),
        udt_definition.name()
    ));

    for (column_name, type_) in udt_definition.types().iter() {
        match type_ {
            CType::Primitive(primitive) => {
                let mut c = PostgresColumn::new(
                    column_name.to_string(),
                    PostgresType::Simple((*primitive).into()),
                );
                c.set_uuid(cassandra_column.uuid());
                udt_table.add_column(c);
            }
            CType::Collection { .. } => return Err(()),
            CType::Tuple(..) => return Err(()),
            CType::Udt { .. } => return Err(()),
        }
    }

    for key in postgres_table.primary_keys().iter() {
        let key_definition = postgres_table.retrieve_column(key).ok_or(())?;
        let mut c = PostgresColumn::new(
            key_definition.name().to_string(),
            key_definition.r#type().clone(),
        );
        c.set_uuid(key_definition.uuid());
        udt_table.add_column(c);
        udt_table.add_primary_key(key.to_string());
    }

    let foreign_keys_name = udt_table
        .primary_keys()
        .iter()
        .map(ToString::to_string)
        .collect::<Vec<_>>();

    udt_table.add_foreign_key(ForeignKey::new(
        keyspace.name().to_string(),
        keyspace.name().to_string(),
        foreign_keys_name.clone(),
        postgres_table.name().to_string(),
        foreign_keys_name,
    ));

    schema.add_table(udt_table);

    Ok(())
}

fn convert_collection(
    keyspace: &Keyspace,
    schema: &mut Schema,
    postgres_table: &mut PTable,
    collection_type: &CollectionType,
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    match collection_type {
        CollectionType::List(type_) => {
            convert_list(schema, postgres_table, type_, cassandra_column)?
        }
        CollectionType::Map(key, value) => {
            convert_map(schema, postgres_table, key, value, cassandra_column)?
        }
        CollectionType::Set(type_) => {
            convert_set(keyspace, schema, postgres_table, type_, cassandra_column)?
        }
    }
    Ok(())
}

fn convert_list(
    schema: &mut Schema,
    postgres_table: &mut PTable,
    type_: &CType,
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    match type_ {
        CType::Collection { .. } | CType::Tuple(..) | CType::Udt { .. } => Err(()),
        CType::Primitive(primitive_type) => {
            let mut converted_table = PTable::new(cassandra_column.name().to_string());
            let mut list_item_column = PostgresColumn::new(
                "list_item".to_string(),
                PostgresType::Simple((*primitive_type).into()),
            );
            list_item_column.set_uuid(cassandra_column.uuid());
            converted_table.add_column(list_item_column);

            for key in postgres_table.primary_keys() {
                let key_column_definition =
                    postgres_table.retrieve_column(key).expect("Logic error.");
                if let PostgresType::Simple(primitive) = key_column_definition.r#type() {
                    let mut key_column =
                        PostgresColumn::new(key.to_string(), PostgresType::Simple(*primitive));
                    key_column.set_uuid(key_column_definition.uuid());
                    converted_table.add_column(key_column);

                    converted_table.add_primary_key(key.to_string());
                } else {
                    return Err(());
                }
            }
            let foreign_columns = postgres_table.primary_keys().to_vec();
            converted_table.add_foreign_key(ForeignKey::new(
                schema.name().to_string(),
                schema.name().to_string(),
                foreign_columns.clone(),
                postgres_table.name().to_string(),
                foreign_columns,
            ));

            schema.add_table(converted_table);

            Ok(())
        }
    }
}
fn convert_map(
    schema: &mut Schema,
    postgres_table: &mut PTable,
    key: &CType,
    value: &CType,
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    match key {
        CType::Primitive(..) => (),
        CType::Collection { .. } | CType::Tuple(..) | CType::Udt { .. } => return Err(()),
    }
    match value {
        CType::Primitive(..) => (),
        CType::Collection { .. } | CType::Tuple(..) | CType::Udt { .. } => return Err(()),
    }
    let mut converted_table = PTable::new(cassandra_column.name().to_string());
    if let CType::Primitive(primitive_key) = key {
        let mut key_column = PostgresColumn::new(
            "key".to_string(),
            PostgresType::Simple((*primitive_key).into()),
        );
        key_column.set_uuid(cassandra_column.uuid());
        converted_table.add_column(key_column);
        if let CType::Primitive(primitive_value) = value {
            let mut value_column = PostgresColumn::new(
                "value".to_string(),
                PostgresType::Simple((*primitive_value).into()),
            );
            value_column.set_uuid(cassandra_column.uuid());
            converted_table.add_column(value_column);
        } else {
            return Err(());
        }

        for key in postgres_table.primary_keys() {
            let key_column_definition = postgres_table.retrieve_column(key).expect("Logic error.");
            if let PostgresType::Simple(primitive) = key_column_definition.r#type() {
                let mut key_column =
                    PostgresColumn::new(key.to_string(), PostgresType::Simple(*primitive));
                key_column.set_uuid(key_column_definition.uuid());
                converted_table.add_column(key_column);

                converted_table.add_primary_key(key.to_string());
            } else {
                return Err(());
            }
        }
        let foreign_columns = postgres_table.primary_keys().to_vec();
        converted_table.add_foreign_key(ForeignKey::new(
            schema.name().to_string(),
            schema.name().to_string(),
            foreign_columns.clone(),
            postgres_table.name().to_string(),
            foreign_columns,
        ));
        schema.add_table(converted_table);
    } else {
        return Err(());
    }
    Ok(())
}
fn convert_set(
    keyspace: &Keyspace,
    schema: &mut Schema,
    postgres_table: &mut PTable,
    type_: &CType,
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    match type_ {
        CType::Collection { .. } | CType::Tuple(..) | CType::Udt { .. } => return Err(()),
        CType::Primitive(..) => (),
    }
    let mut set_table = PTable::new(format!(
        "{}_{}",
        postgres_table.name(),
        cassandra_column.name()
    ));

    postgres_table
        .primary_keys()
        .iter()
        .for_each(|primary_key| {
            set_table.add_primary_key(primary_key.to_string());
            if let Some(column) = postgres_table.retrieve_column(primary_key) {
                set_table.add_column(column.clone());
            }
            set_table.add_foreign_key(ForeignKey::new(
                keyspace.name().to_string(),
                keyspace.name().to_string(),
                set_table.primary_keys().to_vec(),
                postgres_table.name().to_string(),
                postgres_table.primary_keys().to_vec(),
            ));
        });

    match type_ {
        CType::Primitive(primite_type) => {
            let mut column = PostgresColumn::new(
                "element".to_string(),
                PostgresType::Simple((*primite_type).into()),
            );
            column.set_uuid(cassandra_column.uuid());
            set_table.add_column(column);
        }
        CType::Collection { .. } | CType::Tuple(..) | CType::Udt { .. } => unreachable!(),
    }

    schema.add_table(set_table);

    Ok(())
}

fn convert_tuple(
    keyspace: &Keyspace,
    schema: &mut Schema,
    postgres_table: &mut PTable,
    cassandra_types: &[CType],
    cassandra_column: &CassandraColumn,
) -> Result<(), ()> {
    if cassandra_types.iter().any(|t| match t {
        CType::Primitive(_) => false,
        CType::Collection { .. } | CType::Tuple(_) | CType::Udt { .. } => true,
    }) {
        return Err(());
    }

    let mut tuple_table = PTable::new(format!(
        "{}_{}",
        postgres_table.name(),
        cassandra_column.name()
    ));
    tuple_table.set_uuid(postgres_table.uuid());
    let primary_keys = postgres_table.primary_keys();
    primary_keys.iter().for_each(|primary_key| {
        if let Some(key_column) = postgres_table.retrieve_column(primary_key) {
            tuple_table.add_column(key_column.clone());
            tuple_table.add_foreign_key(ForeignKey::new(
                keyspace.name().to_string(),
                keyspace.name().to_string(),
                primary_keys.to_vec(),
                postgres_table.name().to_string(),
                primary_keys.to_vec(),
            ));
            primary_keys
                .iter()
                .for_each(|k| tuple_table.add_primary_key(k.to_string()));
        }
    });

    for (i, type_) in cassandra_types.iter().enumerate() {
        let column_name = format!("element_{}", i);
        match type_ {
            CType::Primitive(primitive_type) => {
                let mut column = PostgresColumn::new(
                    column_name,
                    PostgresType::Simple((*primitive_type).into()),
                );
                column.set_uuid(cassandra_column.uuid());
                tuple_table.add_column(column);
            }
            CType::Collection { .. } | CType::Tuple(..) | CType::Udt { .. } => unreachable!(),
        }
    }

    schema.add_table(tuple_table);

    Ok(())
}
