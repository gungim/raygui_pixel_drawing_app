#ifndef APP_LAYER_PANNEL_H_INCLUDED
#define APP_LAYER_PANNEL_H_INCLUDED

#include "../utils.hpp"
#include "raylib.h"
#include <vector>

namespace app {
    namespace layer {

        class Layer;
        class LayerPannel {
          private:
            std::vector<Layer*> layer;
            int spriteFrames;
            int selectedIndex;
            Vector2i size;
            Vector2 offset;
            Vector2i canvas_size;

          public:
            LayerPannel(Vector2i canvas_size);
            ~LayerPannel();
            void add();
            void remove(int index);
            void addSprite();
            void draw();
            void resize();
        };
    } // namespace layer
} // namespace app
//
#endif // !APP_LAYER_PANNEL_H_INCLUDED
