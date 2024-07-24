#include "raylib.h"
namespace app {
    class MainWindow;
    class Context;
    class TopBar;

    class App {
      private:
        Vector2 screenSize;
        Context* context;
        MainWindow* main_widdow;

      public:
        App();
        ~App();
        void run();
        void init();
    };
} // namespace app
