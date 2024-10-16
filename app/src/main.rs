use std::{fs::File, io::Read};

use cassandra::ast_queries::keyspace_queries::keyspace_query;
use eframe::{run_native, NativeOptions};
use rfd::FileDialog;

mod cassandra;
mod postgres;
mod util;

#[derive(Default)]
struct App {
    dump: String,
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
