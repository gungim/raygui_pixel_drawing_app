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
        GuiLoadIcons("assets/iconset.rgi", true);
    }

    void App::run() {
        InitWindow(this->screenSize.x, this->screenSize.y,
                   "raygui - portable window");
        SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Window configuration flags
        SetTargetFPS(24);
        this->init();

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
