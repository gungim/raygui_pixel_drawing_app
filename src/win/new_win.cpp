#include "new_win.hpp"
#include "../template.hpp"
#include "../workspaces.hpp"
#include "raygui.h"
#include "raylib.h"

#include "cstring"
#include <math.h> // Required for: round()
#include <stdio.h>
#include <stdlib.h> // Required for: atoi()

#include "iostream"
//
namespace app {

    NewWin::NewWin() {
        this->size = {400., 350};
        this->isOpen = false;

        this->width = 32;
        this->height = 32;
        std::strcpy(this->name, "default");
        this->templateIndex = 2;

        this->widthEditMode = false;
        this->nameEditMode = false;
        this->heightEditMode = false;
        this->templateEdit = false;

        this->btnLoadPressed = false;
        this->t_instance = new Templates();
    }
    NewWin::~NewWin() {}
    void NewWin::draw() {
        if (this->isOpen) {
            GuiEnable();
            this->isOpen =
                !GuiWindowBox((Rectangle){this->offset.x, this->offset.y,
                                          this->size.x, this->size.y},
                              "New Project");

            //----------------------------------------------------------------------
            // Name Input
            GuiLabel(
                (Rectangle){this->offset.x + 10, this->offset.y + 70, 80, 25},
                "Project name");
            if (GuiTextBox((Rectangle){this->offset.x + 80 + 10,
                                       this->offset.y + 70,
                                       this->size.x - 20 - 80, 25},
                           this->name, 128, this->nameEditMode)) {
                this->nameEditMode = !this->nameEditMode;
            }

            //----------------------------------------------------------------------
            // Size Input
            GuiGroupBox((Rectangle){this->offset.x + 10, this->offset.y + 110,
                                    this->size.x - 20, 90},
                        "Size");
            //----------------------------------------------------------------------
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 110 + 10, 120, 25},
                            "Width", &this->width, 1, 10000,
                            this->widthEditMode)) {
                this->templateIndex = 0;
                this->widthEditMode = !this->widthEditMode;
            }
            if (GuiValueBox((Rectangle){this->offset.x + 60,
                                        this->offset.y + 110 + 40, 120, 25},
                            "Height", &this->height, 1, 10000,
                            this->heightEditMode)) {
                this->templateIndex = 0;
                this->heightEditMode = !this->heightEditMode;
            }

            //----------------------------------------------------------------------
            // Submit button
            if (GuiButton((Rectangle){this->offset.x + 10,
                                      this->offset.y + this->size.y - 30,
                                      this->size.x - 20, 25},
                          "New")) {
                WorkSpaces* wps = WorkSpaces::instance();
                wps->add(this->width, this->height, this->name);
                this->isOpen = false;
            };

            GuiLabel((Rectangle){this->offset.x + 200,
                                 this->offset.y + 110 + 10, 180, 25},
                     "Template");
            if (GuiDropdownBox((Rectangle){this->offset.x + 200,
                                           this->offset.y + 110 + 40, 180, 25},
                               this->t_instance->tplsStr, &this->templateIndex,
                               this->templateEdit)) {
                if (this->templateIndex != 0) {
                    Template tp =
                        this->t_instance->getList().at(this->templateIndex);

                    this->width = tp.size.x;
                    this->height = tp.size.y;
                }
                this->templateEdit = !this->templateEdit;
            }
            GuiDisable();
            //-----------------------------------------------------------------------
        } else {
            GuiEnable();
        }
    }
} // namespace app
