
#include "raygui.h"

struct DroppedFileConfig {
    char* pixelFormatTextList[8];
    char* channelsTextList[4];
    char* bitDepthTextList[3];
};

namespace app {

    class NewWin {
      private:
        char name[128];
        int width;
        int height;
        Vector2 offset;

        bool nameEditMode;
        bool widthEditMode;
        bool heightEditMode;

        bool open;

        bool btnLoadPressed;
        bool btnNewPressed;

      public:
        NewWin();
        ~NewWin();
        void Draw();
    };
} // namespace app
