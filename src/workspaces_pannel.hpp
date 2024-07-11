#include "raylib.h"

namespace app {
    class WorkSpacesPannel {
      private:
        Vector2 offset;
        float width;
        float height;

      public:
        WorkSpacesPannel();
        ~WorkSpacesPannel();
        void draw();
    };
} // namespace app
