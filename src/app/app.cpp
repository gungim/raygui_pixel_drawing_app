#include "app.hpp"
#include "context.hpp"
#include "main_window.hpp"

#include "raygui.h"

namespace app {
    App::App() { this->screenSize = {800., 600.}; }
    App::~App() {
        this->main_widdow = nullptr;
        this->context = nullptr;
    }
    void App::init() {
        this->context = new Context();
        this->main_widdow = new MainWindow();

        SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Window configuration flags
        GuiLoadStyleDefault();
        GuiLoadIcons("/Users/admin/Dev/cmake/raygui_pixel_drawing_app2/assets/iconset.rgi", true);

        InitWindow(this->screenSize.x, this->screenSize.y,
                   "raygui - portable window");
        SetTargetFPS(24);
    }

    void App::run() {

        while (!WindowShouldClose()) // Detect window close button or ESC key
        {
            // Update
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(RAYWHITE);
            if (this->main_widdow) {
                main_widdow->draw(this->context);
            }
            //----------------------------------------------------------------------------------
            EndDrawing();
        }

        CloseWindow(); // Close window and OpenGL context
    };
} // namespace app
