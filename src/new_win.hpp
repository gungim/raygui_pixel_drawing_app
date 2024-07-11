
#include "raygui.h"

struct DroppedFileConfig {
    char* pixelFormatTextList[8];
    char* channelsTextList[4];
    char* bitDepthTextList[3];
};

namespace app {

    class NewWin {
      private:
        float boxWidth;
        float boxHeight;
        Vector2 offset;
        bool isOpen;

        // Form
        int width;
        int height;
        char name[128];

        bool nameEditMode;
        bool widthEditMode;
        bool heightEditMode;

        bool btnLoadPressed;
        bool btnNewPressed;

      public:
        NewWin();
        ~NewWin();
        void draw();
        void open();
    };
} // namespace app
