#include "topbar.hpp"
#include "./ui/new_win.hpp"
#include "./ui/resize_canvas.hpp"
#include "raygui.h"
#include "style.hpp"
#include "workspaces.hpp"

namespace app {

    TopBar::TopBar() {
        this->newWin = new NewWin();
        this->resizeCanvas = new ResizeCanvasWin();

        this->size = {GetScreenWidth(), 27};
        this->offset = {0, 25};
    }
    TopBar::~TopBar() {
        delete this->newWin;
        delete this->resizeCanvas;
    }
    void TopBar::draw() {
        GuiPanel((Rectangle){this->offset.x, this->offset.y,
                             (float)this->size.x, (float)this->size.y},
                 nullptr);
        // New workspace button
        GuiSetTooltip("Create new project");
        if (GuiButton((Rectangle){ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, BUTTON_ICON_SIZE,
                                  BUTTON_ICON_SIZE},
                      "#8#")) {
            this->newWin->open();
        };
        GuiSetTooltip("Create new project");
        // Save workspace button
        if (GuiButton((Rectangle){(BUTTON_ICON_SIZE + ITEM_SPACING) * 1 +
                                      ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, BUTTON_ICON_SIZE,
                                  BUTTON_ICON_SIZE},
                      "#2#")) {
        };
        GuiSetTooltip("Save project");
        // Upload Image button
        if (GuiButton((Rectangle){(BUTTON_ICON_SIZE + ITEM_SPACING) * 2 +
                                      ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, BUTTON_ICON_SIZE,
                                  BUTTON_ICON_SIZE},
                      "#12#")) {
        };
        GuiSetTooltip("Load image");
        // Resize canvas button
        if (GuiButton((Rectangle){(BUTTON_ICON_SIZE + ITEM_SPACING) * 3 +
                                      ITEM_SPACING + this->offset.x,
                                  4 + this->offset.y, BUTTON_ICON_SIZE,
                                  BUTTON_ICON_SIZE},
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
