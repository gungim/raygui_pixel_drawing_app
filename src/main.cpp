/*******************************************************************************************
 *
 *   raylib [core] example - window scale letterbox (and virtual mouse)
 *
 *   This example has been created using raylib 2.5 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Example contributed by Anata (@anatagawa) and reviewed by Ramon Santamaria
 *(@raysan5)
 *
 *   Copyright (c) 2019 Anata (@anatagawa) and Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/
#include "draw_win.hpp"
#include "import_file.hpp"
#include "raylib.h"
#include "topbar.hpp"
#include <stdio.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    float screenWidth = 800.0;
    float screenHeight = 600.0;

    InitWindow(screenWidth, screenHeight, "raygui - portable window");

    Vector2 windowOffset = {screenWidth / 2 - 200 / 2,
                            screenHeight / 2 - 465 / 2};

    app::Context context = app::Context();
    app::TopBar topbar = app::TopBar();
    app::ImportFile importFile = app::ImportFile();

    // drawWin.CreateTransBG();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Window configuration flags

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        topbar.Draw(&context);

        importFile.Draw(context);

        //----------------------------------------------------------------------------------
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Draw project list scroll bar
void DrawProjectBar() {
    float screenWidth = 600;
    Vector2 scroll = {0, 0};
    Rectangle scissorRec = {0};
    Rectangle panelPounds = {0, 0, screenWidth, 32};
    Rectangle panelContentRec = {0, 0, 1200, 30};
    GuiScrollPanel(panelPounds, NULL, panelContentRec, &scroll, &scissorRec);
    BeginScissorMode(scissorRec.x, scissorRec.y, scissorRec.width,
                     scissorRec.height);

    // for (int i = 0; i <= context.ProjectCount(); i++) {
    //     char* dev = context.projectsName.at(i).data();
    // GuiButton((Rectangle){0, 0, 120, 30}, "Project 1");
    // GuiButton((Rectangle){120 * 1 + 2, 0, 120, 30}, "Project 2");
    // GuiButton((Rectangle){120 * 2 + 2 * 2, 0, 120, 30}, "Project 3");
    // GuiButton((Rectangle){120 * 3 + 2 * 3, 0, 120, 30}, "Project 4");
    // }
    EndScissorMode();
}
