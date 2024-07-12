#include "raylib.h"

namespace app {
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
    };
} // namespace app
