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
use fd::CassandraDependency;
use query::Query;
use relations::{FindRelations, Relations};
use rfd::FileDialog;

mod cassandra;
mod fd;
mod postgres;
mod query;
mod relations;
mod ui;
mod util;

#[derive(Default)]
struct App {
    dump: String,
    parsed_data: Option<Keyspace>,
    fd_files: Option<HashMap<String, File>>,
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
            if ui.button("check query impl").clicked() {
                let query_str = self.parsed_data.as_mut().unwrap().to_query_string();
                println!("{}", query_str);
            }
            if let Some(ref res) = self.parsed_data {
                let mut files = self.fd_files.get_or_insert_with(HashMap::new);
                res.tables().iter().for_each(|table| {
                    if ui
                        .button(format!("Load data for {}", table.name()))
                        .clicked()
                    {
                        if let Some(file) = FileDialog::new()
                            .add_filter("comma separated values", &["csv"])
                            .pick_file()
                        {
                            files.insert(table.name().to_string(), File::open(file).unwrap());
                            println!("inserted key: {} value: ?", table.name(),);
                        }
                    }
                });
            }
            //if ui.button("test postgres conversion").clicked() {
            //    if let Some(ref keyspace) = self.parsed_data {
            //        print!(
            //            "{:#?}",
            //            convert_keyspace_to_schema(keyspace, Relations {}).unwrap()
            //        );
            //    }
            //}
            if ui.button("relations").clicked() {
                println!("{:#?}", self.fd_files);
                if let Some(ref filemap) = self.fd_files {
                    let relation_finder =
                        FindRelations::new(self.parsed_data.as_ref().unwrap(), filemap);
                    let _ = relation_finder.run();
                }
            }
            if ui.button("fds").clicked() {
                let mut deps = CassandraDependency::new(
                    self.fd_files.as_ref().unwrap(),
                    self.parsed_data.as_ref().unwrap(),
                );
                deps.extract_dependencies();
                println!("{}", deps);
                deps.print_dependencies();
                for table in self.parsed_data.as_ref().unwrap().tables().iter() {
                    println!("table: {}", table.name());
                    let ckey = deps.find_candidate_keys_bf(table.name());
                    println!("candidate key: {:#?}", ckey);
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

    // let (worker_tx, worker_rx) = channel::<Box<dyn Event<AppState = MyAppState> + Send>>();
    // let (event_tx, event_rx) = channel::<Box<dyn Event<AppState = MyAppState> + Send>>();
    // let (error_tx, error_rx) = channel::<Box<dyn Error + Send + Sync>>();

    // let options = NativeOptions {
    //     viewport: ViewportBuilder::default().with_inner_size([600.0, 800.0]),
    //     ..Default::default()
    // };

    // std::thread::spawn(move || {
    //     while let Ok(mut event) = worker_rx.recv() {
    //         match event.handle() {
    //             Ok(_) => {}
    //             Err(e) => {
    //                 println!("sending err");
    //                 error_tx.send(e).unwrap();
    //             }
    //         }
    //         event_tx.send(event).unwrap();
    //     }
    // });

    // run_native(
    //     "Valami",
    //     options,
    //     Box::new(|_cc| Ok(MyApp::new(worker_tx, event_rx, error_rx))),
    // )
    // .unwrap();
}
