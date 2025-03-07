use std::{collections::HashMap, error::Error, path::Path};

use csv::{ReaderBuilder, WriterBuilder};

use crate::{
    cassandra::{
        composite_data_parser::CompositeDataParser,
        database::Keyspace,
        types::{CollectionType, Type},
    },
    postgres::database::Schema,
};

pub fn generate_schema_ir(
    old_keyspace: &Keyspace,
    converted_schema: &Schema,
    folder: &Path,
) -> Result<(), Box<dyn Error>> {
    let parser = CompositeDataParser::new();
    for table in converted_schema.tables().iter() {
        let mut new_table_writer = WriterBuilder::new()
            .escape(b'\"')
            .quote(b'\"')
            .from_path(folder.join(format!("{}.IR", table.name())))?;

        let header = table.columns().iter().map(|c| c.name());
        new_table_writer.write_record(header)?;

        let old_table = old_keyspace
            .table_by_coldef_uuid(table.columns()[0].uuid())
            .expect("Logic error");

        let path = folder.join(format!("{}.csv", old_table.name()));

        let mut reader = ReaderBuilder::new()
            .escape(Some(b'\\'))
            .quote(b'\"')
            .has_headers(true)
            .from_path(path)?;

        let lookup_map = reader
            .headers()?
            .iter()
            .enumerate()
            .map(|(x, y)| (y.to_string(), x))
            .collect::<HashMap<_, _>>();

        for record in reader.records() {
            let mut multi_row = Vec::new();
            let record = record?;
            let mut converted_row: HashMap<String, String> = HashMap::new();
            for column in table.columns().iter() {
                let old_column_def = old_keyspace
                    .coldef_by_uuid(column.uuid())
                    .expect("Logic error");

                let literal = record[lookup_map[old_column_def.name()]].to_string();

                match old_column_def.r#type() {
                    Type::Primitive(_) => {
                        converted_row.insert(column.name().to_string(), literal);
                    }
                    Type::Collection { r#type, .. } => match r#type {
                        CollectionType::List(_) => {
                            let list_items = parser.parse_list_literal(&literal);
                            for item in list_items.iter() {
                                let mut new_row = converted_row.clone();
                                new_row.insert(column.name().to_string(), item.to_string());
                                multi_row.push(new_row);
                            }
                        }
                        CollectionType::Map(_, _) => {
                            let map_pairs = parser.parse_map_literal(&literal);
                            for (k, v) in map_pairs.iter() {
                                let mut new_row = converted_row.clone();
                                new_row.insert("key".to_string(), k.to_string());
                                new_row.insert("value".to_string(), v.to_string());
                                if !multi_row.contains(&new_row) {
                                    multi_row.push(new_row);
                                }
                            }
                        }
                        CollectionType::Set(_) => {
                            let set_items = parser.parse_set_literal(&literal);
                            for item in set_items.iter() {
                                let mut new_row = converted_row.clone();
                                new_row.insert(column.name().to_string(), item.to_string());
                                multi_row.push(new_row);
                            }
                        }
                    },
                    Type::Tuple(_) => {
                        let tuple_items = parser.parse_tuple_literal(&literal);
                        for (element_index, item) in tuple_items.iter().enumerate() {
                            let column_name = format!("element_{}", element_index);
                            converted_row.insert(column_name, item.to_string());
                        }
                    }
                    Type::Udt { .. } => {
                        let udt_pairs = parser.parse_udt_literal(&literal);
                        converted_row.insert(
                            column.name().to_string(),
                            udt_pairs[column.name()].to_string(),
                        );
                    }
                }
            }
            for item in multi_row.iter_mut() {
                for (column_name, primitives) in converted_row.iter() {
                    item.insert(column_name.to_string(), primitives.to_string());
                }
            }

            if multi_row.is_empty() {
                let mut ordered_row = Vec::new();
                for column in table.columns().iter() {
                    ordered_row.push(&converted_row[column.name()]);
                }
                new_table_writer.write_record(ordered_row)?;
            } else {
                for row in multi_row.iter() {
                    let mut ordered_row = Vec::new();
                    for column in table.columns().iter() {
                        ordered_row.push(&row[column.name()]);
                    }
                    new_table_writer.write_record(ordered_row)?;
                }
            }
        }
    }

    Ok(())
}
