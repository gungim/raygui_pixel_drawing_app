#include "topbar.hpp"
#include "new_win.hpp"
#include "raygui.h"

namespace app {

    TopBar::TopBar() {
        this->newWin = new NewWin();

        int screenWidth = GetScreenWidth();

        this->width = screenWidth;
        this->height = 32;
    }
    TopBar::~TopBar() {}
    void TopBar::draw(Context* context, Vector2 offset) {
        GuiPanel((Rectangle){0, 0, this->width, this->height}, nullptr);
        if (GuiButton((Rectangle){5, 4, 24, 24}, "#8#")) {
            this->newWin->open();
        };
        GuiButton((Rectangle){(24 + 5) * 1 + 5, 4, 24, 24}, "#2#");
        if (GuiButton((Rectangle){(24 + 5) * 2 + 5, 4, 24, 24}, "#12#")) {
        };

        this->newWin->draw();
    }
} // namespace app
