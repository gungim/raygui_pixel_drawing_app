#ifndef APP_TOPBAR_H_INCLUDED
#define APP_TOPBAR_H_INCLUDED

#include "raylib.h"
#include "utils.hpp"

namespace app {
    class NewWin;
    class ResizeCanvasWin;

    class TopBar {
      private:
        Vector2i size;
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
