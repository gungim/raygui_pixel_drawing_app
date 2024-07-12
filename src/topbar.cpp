#include "topbar.hpp"
#include "raygui.h"
#include "win/new_win.hpp"
#include "win/resize_canvas.hpp"
#include "workspaces.hpp"

namespace app {

    TopBar::TopBar() {
        this->newWin = new NewWin();
        this->resizeCanvas = new ResizeCanvasWin();

        this->width = GetScreenWidth();
        this->height = 32;
    }
    TopBar::~TopBar() {
        delete this->newWin;
        delete this->resizeCanvas;
    }
    void TopBar::draw(Context* context, Vector2 offset) {
        GuiPanel((Rectangle){0, 0, this->width, this->height}, nullptr);
        // New workspace button
        if (GuiButton((Rectangle){5, 4, 24, 24}, "#8#")) {
            this->newWin->open();
        };
        GuiSetTooltip("Create new project");
        // Save workspace button
        if (GuiButton((Rectangle){(24 + 5) * 1 + 5, 4, 24, 24}, "#2#")) {
        };
        GuiSetTooltip("Save project");
        // Upload Image button
        if (GuiButton((Rectangle){(24 + 5) * 2 + 5, 4, 24, 24}, "#12#")) {
        };
        GuiSetTooltip("Load image");
        // Resize canvas button
        if (GuiButton((Rectangle){(24 + 5) * 3 + 5, 4, 24, 24}, "#32#")) {
            WorkSpaces* wps = WorkSpaces::instance();
            Vector2 v = wps->getCurrentSize();
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
