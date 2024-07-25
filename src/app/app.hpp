#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "raylib.h"
namespace app {
    class MainWindow;
    // class TopBar;

    class App {
      private:
        Vector2 screenSize;
        MainWindow* main_widdow;
        bool exitWindow;

      public:
        App();
        ~App();
        void run();
        void init();
    };
} // namespace app
#endif // !APP_H_INCLUDED
