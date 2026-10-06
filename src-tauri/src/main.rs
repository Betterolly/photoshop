#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use serde::Serialize;
use tauri::Manager;

#[derive(Serialize)]
struct EngineInfo { name: &'static str, version: &'static str, backend: &'static str, gpu_ready: bool }

#[tauri::command]
fn engine_info() -> EngineInfo {
    EngineInfo { name: "Betterolly Photo Engine", version: "0.1.0", backend: "Rust + C++ native processing boundary", gpu_ready: false }
}

#[tauri::command]
fn app_health(app: tauri::AppHandle) -> String {
    let path = app.path().app_data_dir().map(|p| p.display().to_string()).unwrap_or_else(|_| "unavailable".into());
    format!("Betterolly Photo native shell ready; app data: {path}")
}

fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![engine_info, app_health])
        .setup(|app| {
            #[cfg(debug_assertions)]
            if let Some(window) = app.get_webview_window("main") { window.set_title("Betterolly Photo").ok(); }
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("error while running Betterolly Photo");
}
