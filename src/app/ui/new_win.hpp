#include "win_widget.hpp"

namespace app {
    class Templates;

    class NewWin : public ui::WinWidget {
      private:
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
    };
} // namespace app
