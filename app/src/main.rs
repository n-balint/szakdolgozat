use eframe::{run_native, NativeOptions};

#[derive(Default)]
struct App {}

impl eframe::App for App {
    fn update(&mut self, _ctx: &egui::Context, _frame: &mut eframe::Frame) {}
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
