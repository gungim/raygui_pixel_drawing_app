#include "topbar.hpp"
#include "raygui.h"
#include "raylib.h"

TopBar::TopBar() {
    this->newWin = NewWin();

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    this->width = screenWidth;
    this->height = 32;
}
TopBar::~TopBar() {}
void TopBar::Draw(Context* context) {
    GuiPanel((Rectangle){0, 0, this->width, this->height}, NULL);
    this->newWin.Draw();
}
