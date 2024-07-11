#include "raylib.h"

namespace app {
    class Context;
    class Toolbar {
      public:
        Toolbar();
        ~Toolbar();
        void draw(Context* context, Vector2 offset);
    };
} // namespace app
