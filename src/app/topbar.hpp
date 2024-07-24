#include "raylib.h"

namespace app {
    class NewWin;
    class Context;
    class ResizeCanvasWin;

    class TopBar {
      private:
        float width;
        float height;

        NewWin* newWin;
        ResizeCanvasWin* resizeCanvas;

      public:
        TopBar();
        ~TopBar();
        void draw(Context* context, Vector2 offset);
        void LoadFile();
    };
} // namespace app
