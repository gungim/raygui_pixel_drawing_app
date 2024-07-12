#ifndef WIN_WIDGET_H_INCLUDED
#define WIN_WIDGET_H_INCLUDED
#pragma once

#include "raylib.h"

namespace ui {
    class WinWidget {
      protected:
        Vector2 offset;
        Vector2 size;
        bool isOpen;

      public:
        void open();
    };
} // namespace ui
#endif
