#include "win_widget.hpp"

namespace app {
    class ResizeCanvasWin : public ui::WinWidget {
      private:
        int width;
        int height;

        bool widthEditMode;
        bool heightEditMode;

      public:
        ResizeCanvasWin();
        ~ResizeCanvasWin();
        void draw();
        void setForm(int w, int h);
    };
} // namespace app
