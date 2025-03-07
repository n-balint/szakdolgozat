use std::{
    error::Error,
    sync::{atomic::AtomicBool, Arc},
};

pub mod cassandra_postgres_migration;
pub mod postgres_cassandra_migration;

pub trait Event {
    type AppState;
    fn handle(&mut self, processing: &Arc<AtomicBool>) -> Result<(), Box<dyn Error + Send + Sync>>;
    fn app_state(&self) -> Self::AppState;
}
