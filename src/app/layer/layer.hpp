#ifndef APP_LAYER_H_INCLUDED
#define APP_LAYER_H_INCLUDED

#include "../utils.hpp"
#include "sprite.hpp"
#include <vector>

namespace app {
    namespace layer {
#define SPRITE_SIZE 30

        class Layer {
          private:
            std::vector<Sprite> sprites;
            float opacity;

          public:
            Layer();
            ~Layer();
            void add(Vector2i size);
            void remove(int index);
            void duplicate(int index);
            void resize(Vector2i size);
            void setOpacity(float op);
            void draw(Vector2i offset, int index);
        };
    } // namespace layer
} // namespace app
#endif
