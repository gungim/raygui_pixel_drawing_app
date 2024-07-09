#include "context.hpp"
#include "raygui.h"

namespace app {

    class ImportFile {
      private:
        int dataSize;
        char fileNamePath[256];
        char fileName[64];

        int widthValue;
        int heightValue;
        int channelsActive;
        int bitDepthActive;
        int pixelFormatActive;
        int headerSizeValue;

        bool widthEditMode;
        bool heightEditMode;
        bool headerSizeEditMode;

        Vector2 offset;
        bool open;
        bool btnLoadPressed;

      public:
        ImportFile();
        ~ImportFile();
        void Draw(Context context);
    };
} // namespace app
