#include "new_win.hpp"
#include "raygui.h"
#include "raylib.h"

#include "cstring"
#include <math.h> // Required for: round()
#include <stdio.h>
#include <stdlib.h> // Required for: atoi()
//
namespace app {

    NewWin::NewWin() {
        this->width = 124;
        this->height = 124;

        std::strcpy(this->name, "default");
        this->widthEditMode = false;
        this->nameEditMode = false;
        this->heightEditMode = false;
        this->btnLoadPressed = false;

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        this->offset = {(float)(screenWidth - 200) / 2,
                        (float)(screenHeight - 465) / 2};
        this->open = false;
    }
    NewWin::~NewWin() {}
    void NewWin::Draw() {
        if (GuiButton((Rectangle){0, 0, 24, 24}, "#8#")) {
            this->open = true;
        };
        if (this->open) {
            this->open = !GuiWindowBox(
                (Rectangle){this->offset.x, this->offset.y, 200, 465},
                "New Project");

            // Size Input
            GuiGroupBox(
                (Rectangle){this->offset.x + 10, this->offset.y + 85, 180, 80},
                "Size");
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 100, 80, 25},
                            "Width", &this->width, 1, 10000,
                            this->widthEditMode)) {
                this->widthEditMode = !this->widthEditMode;
            }
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 130, 80, 25},
                            "Height", &this->height, 1, 10000,
                            this->heightEditMode)) {
                this->heightEditMode = !this->heightEditMode;
            }
            //----------------------------------------------------------------------
            // Name Input
            GuiLabel(
                (Rectangle){this->offset.x + 10, this->offset.y + 170, 33, 25},
                "Name");
            if (GuiTextBox((Rectangle){this->offset.x + 10,
                                       this->offset.y + 190, 180, 25},
                           this->name, 128, this->nameEditMode)) {
                this->nameEditMode = !this->nameEditMode;
            }
            //----------------------------------------------------------------------
            // Submit button
            this->btnLoadPressed = GuiButton(
                (Rectangle){this->offset.x + 10, this->offset.y + 225, 180, 25},
                "New");
            //-----------------------------------------------------------------------
        }
        if (this->btnLoadPressed) {
        }
    }
} // namespace app
