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

    Context context = Context();
    DrawWin drawWin = DrawWin(700, 800);
    TopBar topbar = TopBar();
    ImportFile importFile = ImportFile();

    Vector2 scroll = {0, 0};
    Rectangle scissorRec = {0};
    Rectangle panelPounds = {0, 0, screenWidth, 32};
    Rectangle panelContentRec = {0, 0, 1200, 30};

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
        // topbar.Draw(&context);

        // Draw project list scroll bar
        GuiScrollPanel(panelPounds, NULL, panelContentRec, &scroll,
                       &scissorRec);
        BeginScissorMode(scissorRec.x, scissorRec.y, scissorRec.width,
                         scissorRec.height);

        GuiGrid((Rectangle){panelPounds.x + scroll.x, panelPounds.y + scroll.y,
                            panelContentRec.width, panelContentRec.height},
                NULL, 16, 3, NULL);
        EndScissorMode();

        // importFile.Draw(context);

        //----------------------------------------------------------------------------------
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
