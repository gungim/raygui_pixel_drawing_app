#include "layer.hpp"
#include "app/workspaces.hpp"
#include "iostream"
#include "raylib.h"

namespace app {
    namespace layer {

        Layer::Layer() {}
        Layer::~Layer() {
            for (Sprite spr : this->sprites) {
                UnloadImage(*spr.image);
                UnloadTexture(*spr.texture);
            }
            this->sprites.clear();
        }

        void Layer::add(Vector2i n_size) {
            Image image = GenImageColor(n_size.x, n_size.y, BLUE);
            Texture texture = LoadTextureFromImage(image);

            Sprite spr = {&texture, &image};
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

        void Layer::draw(Vector2i offset, int index) {

            std::string s = std::to_string(index);
            const char* text = s.c_str();
            std::cout << this->sprites.size() << std::endl;
            GuiLabel((Rectangle){(float)offset.x + 15, (float)offset.y + 30, 10,
                                 SPRITE_SIZE},
                     text);
            for (int i = 0; i < this->sprites.size(); i++) {
                // DrawRectangleV(
                //     (Vector2){(float)offset.x + (SPRITE_SIZE + 5) * (i + 1),
                //               (float)offset.y + SPRITE_SIZE},
                //     {SPRITE_SIZE, SPRITE_SIZE}, RED);
                DrawTextureRec(
                    *this->sprites.at(i).texture,
                    (Rectangle){0.0f, 0.0f, SPRITE_SIZE, SPRITE_SIZE},
                    (Vector2){(float)offset.x + (SPRITE_SIZE + 5) * i + 10,
                              (float)offset.y + SPRITE_SIZE},
                    RED);
            }
        }
    } // namespace layer
} // namespace app
