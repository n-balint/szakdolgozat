use std::{collections::HashMap, fs::File, io::Read, path::PathBuf};

use cassandra::{
    ast_queries::{
        create_type_queries::udt_query, keyspace_queries::keyspace_query, parse_database,
        table_queries::table_query,
    },
    database::Keyspace,
    migration::conversion::convert_keyspace_to_schema,
};
use eframe::{run_native, NativeOptions};
use rfd::FileDialog;

mod cassandra;
mod fd;
mod postgres;
mod relations;
mod util;

#[derive(Default)]
struct App {
    dump: String,
    parsed_data: Option<Keyspace>,
    fd_files: Option<HashMap<String, PathBuf>>,
}

impl eframe::App for App {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        egui::CentralPanel::default().show(ctx, |ui| {
            let mut dialog = None;
            if ui.button("Open dump").clicked() {
                dialog = FileDialog::new()
                    .add_filter("Cassandra dump", &["cql"])
                    .pick_file();
            }
            if let Some(path) = dialog {
                let _ = File::open(&path).unwrap().read_to_string(&mut self.dump);
            }
            if ui.button("extract keyspace info").clicked() {
                let mut parser = tree_sitter::Parser::new();
                parser.set_language(&tree_sitter_cql::language()).unwrap();
                let root = parser.parse(&self.dump, None).unwrap();
                if let Ok(res) = keyspace_query(&self.dump, &root) {
                    println!("{:#?}", res);
                } else {
                    println!("error parsing keyspace");
                }
            }
            if ui.button("extract table info").clicked() {
                let mut parser = tree_sitter::Parser::new();
                parser.set_language(&tree_sitter_cql::language()).unwrap();
                let root = parser.parse(&self.dump, None).unwrap();
                if let Ok(res) = table_query(&self.dump, &root) {
                    println!("{:#?}", res);
                } else {
                    println!("error parsing table info");
                }
            }
            if ui.button("extract typedefs").clicked() {
                let mut parser = tree_sitter::Parser::new();
                parser.set_language(&tree_sitter_cql::language()).unwrap();
                let root = parser.parse(&self.dump, None).unwrap();
                if let Ok(res) = udt_query(&self.dump, &root) {
                    println!("{:#?}", res);
                } else {
                    println!("error parsing table info");
                }
            }
            if ui.button("parse full db").clicked() {
                let mut parser = tree_sitter::Parser::new();
                parser.set_language(&tree_sitter_cql::language()).unwrap();
                let root = parser.parse(&self.dump, None).unwrap();
                match parse_database(&self.dump, &root) {
                    Ok(res) => {
                        println!("{:#?}", res);
                        self.parsed_data = Some(res);
                    }
                    Err(_) => {
                        println!("failed to parse datapase");
                        self.parsed_data = None;
                    }
                }
            }
            if let Some(ref res) = self.parsed_data {
                let mut files = HashMap::new();
                res.tables().iter().for_each(|table| {
                    if ui
                        .button(format!("Load data for {}", table.name()))
                        .clicked()
                    {
                        let file = FileDialog::new()
                            .add_filter("comma separated values", &["csv"])
                            .pick_file()
                            .unwrap();
                        files.insert(table.name().to_string(), file);
                    }
                });
                self.fd_files = Some(files);
            }
            if ui.button("test postgres conversion").clicked() {
                if let Some(ref keyspace) = self.parsed_data {
                    print!("{:#?}", convert_keyspace_to_schema(keyspace).unwrap());
                }
            }
        });
    }
}

fn main() {
    let options = NativeOptions {
        viewport: egui::ViewportBuilder::default().with_inner_size([600.0, 800.0]),
        ..Default::default()
    };

    run_native(
        "Hello, world",
        options,
        Box::new(|_cc| Ok(Box::<App>::default())),
    )
    .expect("Failed to create native window.");
}
