
#include "raygui.h"

namespace app {
    class Templates;

    class NewWin {
      private:
        Vector2 size;
        Vector2 offset;
        bool isOpen;

        // Form
        int width;
        int height;
        char name[128];
        int templateIndex;

        bool nameEditMode;
        bool widthEditMode;
        bool heightEditMode;
        bool templateEdit;

        bool btnLoadPressed;
        bool btnNewPressed;
        Templates* t_instance;

      public:
        NewWin();
        ~NewWin();
        void draw();
        void open();
    };
} // namespace app
