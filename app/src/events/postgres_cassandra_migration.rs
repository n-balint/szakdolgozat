use std::sync::atomic::Ordering;

use crate::ui::MigrateAppState;

use super::Event;

pub(crate) struct PostgresCassandraMigrationEvent {
    app_state: MigrateAppState,
}

impl Event for PostgresCassandraMigrationEvent {
    type AppState = MigrateAppState;

    fn handle(
        &mut self,
        processing: &std::sync::Arc<std::sync::atomic::AtomicBool>,
    ) -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
        processing.store(true, Ordering::SeqCst);
        Ok(())
    }

    fn app_state(&self) -> Self::AppState {
        self.app_state.clone()
    }
}
