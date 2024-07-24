#include "raylib.h"
#include "../utils/app_utils.hpp"

using namespace utils;
namespace app {
    class Toolbar;
    class LayerPannel;

    struct WPConfig {
        Vector2 offset;
        Vector2i size;
        char* name;
    };

    class WorkSpace {
      private:
        Texture2D texture;
        Texture2D transBG;
        WPConfig* config;
        LayerPannel* l_pannel;

        float scale;
        float rotate;
        Camera2D camera;
        Image image;

        Vector2i startPoint;
        Vector2i endPoint;
        // Brush
        Color color;
        int thick;

        bool saved;

      public:
        WorkSpace(Vector2i s);
        ~WorkSpace();
        void initialize();
        void resize(Vector2i s);
        void draw();
        void zoom();
        void move();
        void close();
        void loadTexture(Image img);
        Vector2i getSize();
        void control();
        void paintPixel(Vector2i point, Color cl);
        void paintLine(Vector2i start, Vector2i end, Color cl);
        void paintCircle(Vector2i centerPoint, int radius);
        void paintEllipse(Vector2i centerPoint, int radiusX, int radiusY);
        // horizontal and vertical lines
        void paintLineHV(Color cl);
        Vector2i GetPixelPositionInWorld(Vector2 position);
    };
} // namespace app
