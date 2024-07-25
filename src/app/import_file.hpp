#ifndef APP_IMPORT_FILE_H_INCLUDED
#define APP_IMPORT_FILE_H_INCLUDED

#include "raylib.h"

namespace app {
    class Context;

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
#endif // !APP_IMPORT_FILE_H_INCLUDED
