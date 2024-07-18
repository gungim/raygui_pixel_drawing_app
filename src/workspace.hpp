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
        Camera2D camera;
        Image image;

        Vector2i startPoint;
        Vector2i endPoint;
        // Brush
        Color color;
        int thick;

        bool saved;

        bool outlineMode;

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
        void paintPixel(Vector2i point, Color cl);
        void paintLine(Vector2i start, Vector2i end, Color cl);
        void paintCircle(Vector2i centerPoint, float radius);
        void paintEllipse(Vector2i centerPoint);
        // horizontal and vertical lines
        void paintLineHV(Color cl);
        Vector2i GetPixelPositionInWorld(Vector2 position);
    };
} // namespace app
