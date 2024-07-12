#include "topbar.hpp"
#include "new_win.hpp"
#include "raygui.h"
// #include "resize_canvas.hpp"

namespace app {

    TopBar::TopBar() {
        this->newWin = new NewWin();
        // this->resizeCanvas = new ResizeCanvasWin();

        int screenWidth = GetScreenWidth();

        this->width = screenWidth;
        this->height = 32;
    }
    TopBar::~TopBar() {}
    void TopBar::draw(Context* context, Vector2 offset) {
        GuiPanel((Rectangle){0, 0, this->width, this->height}, nullptr);
        // New workspace button
        if (GuiButton((Rectangle){5, 4, 24, 24}, "#8#")) {
            this->newWin->open();
        };
        // Save workspace button
        if (GuiButton((Rectangle){(24 + 5) * 1 + 5, 4, 24, 24}, "#2#")) {
        };
        // Upload Image button
        if (GuiButton((Rectangle){(24 + 5) * 2 + 5, 4, 24, 24}, "#12#")) {
        };
        // Resize canvas button
        if (GuiButton((Rectangle){(24 + 5) * 3 + 5, 4, 24, 24}, "#32#")) {
        }

        this->newWin->draw();
    }
} // namespace app
