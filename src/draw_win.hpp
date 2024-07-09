#include "context.hpp"
#include "raylib.h"

namespace app {

    class DrawWin {
      private:
        int width;
        int height;
        Texture texture;

        Image image;
        float scale;
        Vector2 offset;
        Project project;

      protected:
        Texture2D textureBg;

      public:
        DrawWin();
        ~DrawWin();
        void Draw();
        void DrawPixel();
        void LoadProject();
    };
} // namespace app
