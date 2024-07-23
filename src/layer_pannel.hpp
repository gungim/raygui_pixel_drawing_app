#include "utils/app_utils.hpp"
#include "raylib.h"
#include <vector>
using namespace utils;
namespace app {
    struct Sprite {
        Image* image;
    };
    struct WPConfig;
    class Layer {
      private:
        std::vector<Sprite> sprites;
        float opacity;

      public:
        void add(Vector2i size);
        void remove(int index);
        void duplicate(int index);
        void resize(Vector2i size);
        void setOpacity(float op);
        void draw(Vector2i offset);
    };
    class LayerPannel {
      private:
        std::vector<Layer*> layer;
        int spriteFrames;
        int selectedIndex;
        Vector2 size;
        Vector2 offset;
        WPConfig* wp_config;

      public:
        LayerPannel(WPConfig* wp_config);
        ~LayerPannel();
        void add();
        void remove(int index);
        void addSprite();
        void draw();
        void resize();
    };
} // namespace app
