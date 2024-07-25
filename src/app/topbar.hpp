#ifndef APP_TOPBAR_H_INCLUDED
#define APP_TOPBAR_H_INCLUDED

#include "raylib.h"

namespace app {
    class NewWin;
    class ResizeCanvasWin;
#define TOPBAR_ITEM_SPACING 4
#define TOPBAR_ITEM_SIZE 24

    class TopBar {
      private:
        Vector2 size;
        Vector2 offset;

        NewWin* newWin;
        ResizeCanvasWin* resizeCanvas;

      public:
        TopBar();
        ~TopBar();
        void draw();
        void LoadFile();
    };
} // namespace app
#endif // !APP_TOPBAR_H_INCLUDED
