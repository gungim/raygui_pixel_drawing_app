#include "resize_canvas.hpp"
#include "../workspaces.hpp"
#include "raygui.h"
namespace app {
    ResizeCanvasWin::ResizeCanvasWin() {
        this->size = {250, 300};
        this->width = 0;
        this->height = 0;

        this->widthEditMode = false;
        this->heightEditMode = false;
    }
    ResizeCanvasWin::~ResizeCanvasWin() {}
    void ResizeCanvasWin::setForm(int w, int h) {
        this->width = w;
        this->height = h;
    }
    void ResizeCanvasWin::draw() {
        if (this->isOpen) {
            this->isOpen =
                !GuiWindowBox((Rectangle){this->offset.x, this->offset.y,
                                          this->size.x, this->size.y},
                              "Resize canvas");
            //----------------------------------------------------------------------
            // Size Input
            GuiGroupBox((Rectangle){this->offset.x + 10, this->offset.y + 70,
                                    this->size.x - 20, 90},
                        "Size");
            //----------------------------------------------------------------------
            if (GuiValueBox(
                    (Rectangle){this->offset.x + 55, this->offset.y + 70 + 10,
                                this->size.x - 80, 25},
                    "Width", &this->width, 1, 10000, this->widthEditMode)) {
                this->widthEditMode = !this->widthEditMode;
            }
            if (GuiValueBox((Rectangle){this->offset.x + 55,
                                        this->offset.y + 70 + 10 + 30,
                                        this->size.x - 80, 25},
                            "Height", &this->height, 1, 10000,
                            this->heightEditMode)) {
                this->heightEditMode = !this->heightEditMode;
            }

            //----------------------------------------------------------------------
            // Submit button
            if (GuiButton((Rectangle){this->offset.x + 10,
                                      this->offset.y + this->size.y - 30,
                                      this->size.x - 20, 25},
                          "Resize")) {
                WorkSpaces* wps = WorkSpaces::instance();
                wps->resize(this->width, this->height);
                this->isOpen = false;
            };
        }
    }
} // namespace app
