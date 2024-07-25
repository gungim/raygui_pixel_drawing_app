#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS

#include "app.hpp"
#include "main_window.hpp"

namespace app {
    App::App() {
        this->screenSize = {800., 600.};
        this->exitWindow = false;
    }
    App::~App() { this->main_widdow = nullptr; }
    void App::init() {
        this->main_widdow = new MainWindow();

        SetConfigFlags(FLAG_WINDOW_UNDECORATED);
        SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Window configuration flags
                                               //
        GuiLoadIcons("/Users/admin/Dev/cmake/raygui_pixel_drawing_app2/assets/"
                     "iconset.rgi",
                     true);

        InitWindow(this->screenSize.x, this->screenSize.y,
                   "raygui - portable window");
        SetTargetFPS(24);
    }

    void App::run() {

        while (!WindowShouldClose() &&
               !this->exitWindow) // Detect window close button or ESC key
        {
            // Update
            //----------------------------------------------------------------------------------
            BeginDrawing();

            exitWindow = GuiWindowBox(
                (Rectangle){0, 0, this->screenSize.x, this->screenSize.y},
                "#198# PORTABLE WINDOW");
            ClearBackground(RAYWHITE);
            main_widdow->draw();

            //----------------------------------------------------------------------------------
            EndDrawing();
        }

        CloseWindow(); // Close window and OpenGL context
    };
} // namespace app
