use std::{
    borrow::BorrowMut,
    collections::HashMap,
    fs::File,
    io::Read,
    path::PathBuf,
    sync::{atomic::Ordering, mpsc::channel, Arc},
};

use cassandra::{
    ast_queries::{
        create_type_queries::udt_query, keyspace_queries::keyspace_query, parse_database,
        table_queries::table_query,
    },
    database::Keyspace,
    migration::conversion::convert_keyspace_to_schema,
};
use eframe::{run_native, NativeOptions};
use egui::ViewportBuilder;
use env_logger::fmt::TimestampPrecision;
use events::Event;
use fd::CassandraDependency;
use log::{debug, info};
use query::Query;
use relations::{FindRelations, Relations};
use rfd::FileDialog;
use std::error::Error;
use ui::{App, MigrateAppState};

mod cassandra;
mod events;
mod fd;
mod postgres;
mod query;
mod relations;
mod ui;
mod util;

fn main() {
    pretty_env_logger::formatted_timed_builder()
        .parse_default_env()
        .format_timestamp(Some(TimestampPrecision::Millis))
        .init();
    let (worker_tx, worker_rx) = channel::<Box<dyn Event<AppState = MigrateAppState> + Send>>();
    let (event_tx, event_rx) = channel::<Box<dyn Event<AppState = MigrateAppState> + Send>>();
    let (error_tx, error_rx) = channel::<Box<dyn Error + Send + Sync>>();

    let options = NativeOptions {
        viewport: ViewportBuilder::default().with_inner_size([600.0, 800.0]),
        ..Default::default()
    };
    let app = Box::new(App::new(worker_tx, event_rx, error_rx));
    let processing_bool = Arc::clone(&app.is_processing_event);
    info!("Created application context.");

    std::thread::spawn(move || {
        info!("Spawned worker background thread.");
        while let Ok(mut event) = worker_rx.recv() {
            match event.handle(&processing_bool) {
                Ok(_) => {
                    debug!("Handling Ok event.");
                    processing_bool.store(false, Ordering::SeqCst);
                    debug!("Event handled.");
                }
                Err(e) => {
                    debug!("Handling Err event.");
                    processing_bool.store(false, Ordering::SeqCst);
                    debug!("Sending error: {e} to UI.");
                    error_tx.send(e).unwrap();
                }
            }
            debug!("Sending app state update");
            event_tx.send(event).unwrap();
        }
    });
    info!("Starting egui window.");
    run_native("Valami", options, Box::new(|_cc| Ok(app))).unwrap();
}
