#include "layer_pannel.hpp"
#include "../style.hpp"
#include "../workspace.hpp"
#include "app/workspaces.hpp"
#include "layer.hpp"
#include "raygui.h"
#include "raylib.h"

#include "iostream"

namespace app {

    namespace layer {
        LayerPannel::LayerPannel(Vector2i c_size) {
            this->layer = {};
            this->spriteFrames = 1;
            this->selectedIndex = 0;
            this->canvas_size = c_size;

            int screenW = GetScreenWidth();
            int screenH = GetScreenHeight();
            this->size = {screenW, 200};
            this->offset = {0, screenH - (float)this->size.y};
        }

        LayerPannel::~LayerPannel() { this->layer.clear(); }

        void LayerPannel::add() {
            Layer* l = new Layer();
            l->add(this->canvas_size);
            l->resize(this->canvas_size);
            this->layer.push_back(l);
        }

        void LayerPannel::remove(int index) {
            this->layer.erase(this->layer.begin() + index);
        }

        void LayerPannel::addSprite() {
            WorkSpaces* wps = WorkSpaces::instance();
            for (Layer* l : this->layer) {
                l->add(this->canvas_size);
            }
        }

        void LayerPannel::draw() {
            GuiPanel((Rectangle){this->offset.x, this->offset.y,
                                 (float)this->size.x, 32},
                     nullptr);
            //----------------------Left Button-----------------------------
            if (GuiButton((Rectangle){ITEM_SPACING + this->offset.x,
                                      this->offset.y + 4, BUTTON_ICON_SIZE,
                                      BUTTON_ICON_SIZE},
                          "#8#")) {
                this->add();
            }
            if (GuiButton((Rectangle){(BUTTON_ICON_SIZE + ITEM_SPACING) * 1 +
                                          this->offset.x + ITEM_SPACING,
                                      this->offset.y + 4, BUTTON_ICON_SIZE,
                                      BUTTON_ICON_SIZE},
                          "#9#")) {
            }
            //--------------------END Left Button---------------------------
            //----------------------Right Button----------------------------
            if (GuiButton((Rectangle){(float)this->size.x -
                                          (BUTTON_ICON_SIZE + ITEM_SPACING),
                                      this->offset.y + 4, BUTTON_ICON_SIZE,
                                      BUTTON_ICON_SIZE},
                          "#222#")) {
                this->addSprite();
            }
            //--------------------END Right Button--------------------------

            // Draw layer control
            for (int i = 0; i < this->layer.size(); i++) {
                Vector2i l_offset = {0, (int)this->offset.y + 10 +
                                            i * (SPRITE_SIZE + 5)};
                this->layer.at(i)->draw(l_offset, i);
            }
        }

        void LayerPannel::resize() {
            WorkSpaces* wps = WorkSpaces::instance();
            Vector2i currentSize = wps->getActive()->getSize();

            for (Layer* l : this->layer) {
                l->resize(currentSize);
            }
        }
        // ------------ end layer pannel ----------------
    } // namespace layer
} // namespace app
