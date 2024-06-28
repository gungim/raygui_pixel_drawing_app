#include "new_win.h"
#include "raygui.h"
#include "raylib.h"

#include "iostream"
NewWin::NewWin() {
  this->width = 124;
  this->height = 124;
  std::strcpy(name, "default");
  this->widthEditMode = false;
  this->nameEditMode = false;
  this->heightEditMode = false;
  this->open = false;
}
NewWin::~NewWin() {}
void NewWin::draw(float offsetX, float offsetY) {
  // Size Input
  if (this->open) {
    this->open =
        !GuiWindowBox((Rectangle){offsetX, offsetY, 200, 465}, "New Project");

    GuiGroupBox((Rectangle){offsetX + 10, offsetY + 85, 180, 80}, "Size");
    if (GuiValueBox((Rectangle){offsetX + 60, offsetY + 100, 80, 25}, "Width",
                    &this->width, 1, 10000, this->widthEditMode)) {
      this->widthEditMode = !this->widthEditMode;
    }
    if (GuiValueBox((Rectangle){offsetX + 60, offsetY + 130, 80, 25}, "Height",
                    &this->height, 1, 10000, this->heightEditMode)) {
      this->heightEditMode = !this->heightEditMode;
    }
    //----------------------------------------------------------------------
    // Name Input
    GuiLabel((Rectangle){offsetX + 10, offsetY + 170, 33, 25}, "Name");
    if (GuiTextBox((Rectangle){offsetX + 10, offsetY + 190, 80, 25}, this->name,
                   128, this->nameEditMode)) {
      this->nameEditMode = !this->nameEditMode;
    }
    //----------------------------------------------------------------------
    // Submit button
    if (GuiButton((Rectangle){offsetX + 10, offsetY + 225, 180, 25}, "New") ==
        1) {
      std::cout << this->width << ", " << this->height << ", " << this->name
                << std::endl;
    }
    //-----------------------------------------------------------------------
  }
}

void NewWin::enable() { this->open = !this->open; }
bool NewWin::isOpen() { return this->open; }
