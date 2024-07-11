#include "new_win.hpp"
#include "raygui.h"
#include "raylib.h"
#include "workspaces.hpp"

#include "cstring"
#include <math.h> // Required for: round()
#include <stdio.h>
#include <stdlib.h> // Required for: atoi()

#include "iostream"
//
namespace app {

    NewWin::NewWin() {
        this->boxWidth = 200;
        this->boxHeight = 465;
        this->offset = {0, 0};
        this->isOpen = false;

        this->width = 124;
        this->height = 124;
        std::strcpy(this->name, "default");

        this->widthEditMode = false;
        this->nameEditMode = false;
        this->heightEditMode = false;
        this->btnLoadPressed = false;
    }
    NewWin::~NewWin() {}
    void NewWin::draw() {
        if (this->isOpen) {
            this->isOpen =
                !GuiWindowBox((Rectangle){this->offset.x, this->offset.y,
                                          this->boxWidth, this->boxHeight},
                              "New Project");

            // Size Input
            GuiGroupBox(
                (Rectangle){this->offset.x + 10, this->offset.y + 85, 180, 80},
                "Size");
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 100, 120, 25},
                            "Width", &this->width, 1, 10000,
                            this->widthEditMode)) {
                this->widthEditMode = !this->widthEditMode;
            }
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 130, 120, 25},
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
            if (GuiButton((Rectangle){this->offset.x + 10, this->offset.y + 225,
                                      180, 25},
                          "New")) {
                WorkSpaces* wps = WorkSpaces::instance();
                wps->add(this->width, this->height, this->name);
                this->isOpen = false;
            };
            //-----------------------------------------------------------------------
        }
    }
    void NewWin::open() {

        this->isOpen = true;

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        this->offset = {(float)(screenWidth - this->boxWidth) / 2,
                        (float)(screenHeight - this->boxHeight) / 2};
    }
} // namespace app
