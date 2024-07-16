#include "app_utils.hpp"
#include "raylib.h"

namespace app {
    class Toolbar;

    class WorkSpace {
      private:
        Texture2D texture;
        Texture2D transBG;
        Vector2 offset;
        Vector2 size;
        char* name;

        float scale;
        float rotate;
        Vector2 boxOffset;
        Camera2D camera;
        Image image;

        Vector2i startPoint;
        Vector2i endPoint;
        Color color;

      public:
        WorkSpace();
        ~WorkSpace();
        void initialize();
        void reSize(Vector2 s);
        void draw();
        void zoom();
        void move();
        void close();
        void loadTexture(Image img);
        Vector2 getSize();
        void control();
        void paintPixel(Vector2i point);
        void paintLine(Vector2i start, Vector2i end);
        void endPaint();
        void paintCircle(bool circle);
        Vector2i GetPixelPositionInWorld(Vector2 position);
    };
} // namespace app
