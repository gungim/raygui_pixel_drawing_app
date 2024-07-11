#include "raylib.h"

namespace app {
    class NewWin;
    class Context;

    class TopBar {
      private:
        float width;
        float height;

        NewWin* newWin;

      public:
        TopBar();
        ~TopBar();
        void draw(Context* context, Vector2 offset);
        void LoadFile();
    };
} // namespace app
