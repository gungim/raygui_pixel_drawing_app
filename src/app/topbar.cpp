#include "topbar.hpp"
#include "./ui/new_win.hpp"
#include "./ui/resize_canvas.hpp"
#include "raygui.h"
#include "workspaces.hpp"

namespace app {

    TopBar::TopBar() {
        this->newWin = new NewWin();
        this->resizeCanvas = new ResizeCanvasWin();

        this->size = {(float)GetScreenWidth(), 27};
        this->offset = {0, 25};
    }
    TopBar::~TopBar() {
        delete this->newWin;
        delete this->resizeCanvas;
    }
    void TopBar::draw() {
        GuiPanel((Rectangle){this->offset.x, this->offset.y, this->size.x,
                             this->size.y},
                 nullptr);
        // New workspace button
        GuiSetTooltip("Create new project");
        if (GuiButton((Rectangle){TOPBAR_ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, TOPBAR_ITEM_SIZE,
                                  TOPBAR_ITEM_SIZE},
                      "#8#")) {
            this->newWin->open();
        };
        GuiSetTooltip("Create new project");
        // Save workspace button
        if (GuiButton((Rectangle){(TOPBAR_ITEM_SIZE + TOPBAR_ITEM_SPACING) * 1 +
                                      TOPBAR_ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, TOPBAR_ITEM_SIZE,
                                  TOPBAR_ITEM_SIZE},
                      "#2#")) {
        };
        GuiSetTooltip("Save project");
        // Upload Image button
        if (GuiButton((Rectangle){(TOPBAR_ITEM_SIZE + TOPBAR_ITEM_SPACING) * 2 +
                                      TOPBAR_ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, TOPBAR_ITEM_SIZE,
                                  TOPBAR_ITEM_SIZE},
                      "#12#")) {
        };
        GuiSetTooltip("Load image");
        // Resize canvas button
        if (GuiButton((Rectangle){(TOPBAR_ITEM_SIZE + TOPBAR_ITEM_SPACING) * 3 +
                                      TOPBAR_ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, TOPBAR_ITEM_SIZE,
                                  TOPBAR_ITEM_SIZE},
                      "#32#")) {
            Vector2i v = WorkSpaces::instance()->getCurrentSize();
            if (v.x + v.y != 0) {
                this->resizeCanvas->setForm(v.x, v.y);
                this->resizeCanvas->open();
            }
        }
        GuiSetTooltip("Resize canvas");

        this->newWin->draw();
        this->resizeCanvas->draw();
    }
} // namespace app
