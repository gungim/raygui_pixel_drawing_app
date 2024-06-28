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
#include "new_win.h"
#include "raylib.h"
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

  Vector2 windowOffset = {screenWidth / 2 - 200 / 2,
                          screenHeight / 2 - 465 / 2};

  NewWin new_win = NewWin();

  //

  InitWindow(screenWidth, screenHeight, "raygui - portable window");

  SetTargetFPS(60);
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    if (new_win.isOpen()) {
      new_win.draw(windowOffset.x, windowOffset.y);
    } else {
      if (GuiButton(
              (Rectangle){windowOffset.x + 200, windowOffset.y + 500, 30, 25},
              "New")) {
        new_win.enable();
      }
    }

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
