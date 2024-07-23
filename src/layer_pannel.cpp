#include "layer_pannel.hpp"
#include "raygui.h"
#include "raylib.h"
#include "workspace.hpp"

namespace app {

    LayerPannel::LayerPannel(WPConfig* wp) {
        this->layer = {};
        this->spriteFrames = 1;
        this->selectedIndex = 0;

        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();
        this->size = {(float)screenW, 200};
        this->offset = {0, screenH - this->size.y};
        this->wp_config = wp;
    }
    LayerPannel::~LayerPannel() { this->layer.clear(); }
    void LayerPannel::add() {
        Layer* l = new Layer();
        this->layer.push_back(l);
    }
    void LayerPannel::remove(int index) {
        this->layer.erase(this->layer.begin() + index);
    }
    void LayerPannel::addSprite() {
        for (Layer* l : this->layer) {
            l->add(this->wp_config->size);
        }
    }
    void LayerPannel::draw() {
        GuiPanel((Rectangle){this->offset.x, this->offset.y, this->size.x,
                             this->size.y},
                 "Menu");
        DrawLineV({0, this->offset.y + 32}, {this->size.x, this->offset.y + 32},
                  GetColor(GuiGetStyle(STATUSBAR, BORDER_COLOR_NORMAL)));
        for (Layer* l : this->layer) {
            Vector2i offset = {0, 0};
            l->draw(offset);
        }
    }
    void LayerPannel::resize() {
        for (Layer* l : this->layer) {
            l->resize(this->wp_config->size);
        }
    }
    // ------------ end layer pannel ----------------
    void Layer::add(Vector2i size) {
        Image img = GenImageColor(size.x, size.y, BLANK);
        Sprite spr = {&img};
        this->sprites.push_back(spr);
    }
    void Layer::resize(Vector2i size) {}

    void Layer::duplicate(int index) {
        Sprite spr = this->sprites.at(index);
        this->sprites.insert(this->sprites.begin() + index, spr);
    }
    void Layer::remove(int index) {
        this->sprites.erase(this->sprites.begin() + index);
    }
    void Layer::setOpacity(float o) { this->opacity = o; }
    void Layer::draw(Vector2i offset) {

}
} // namespace app
