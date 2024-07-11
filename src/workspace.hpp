#include "raylib.h"

namespace app {
    class WorkSpace {
      private:
        Texture2D texture;
        Texture2D transBG;
        Vector2 offset;
        int width;
        int height;
        char* name;

        float scale;
        float rotate;
        Vector2 boxOffset;
        Camera2D camera;

      public:
        WorkSpace();
        WorkSpace(int w, int h, char* n);
        ~WorkSpace();
        void draw();
        void zoom();
        void move();
        void setupTexture();
        void close();
    };
} // namespace app
