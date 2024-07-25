#ifndef APP_MAIN_WINDOW_H_INCLUDED
#define APP_MAIN_WINDOW_H_INCLUDED

namespace app {
    class WorkSpaces;
    class TopBar;
    class Toolbar;

    class MainWindow {
      private:
        WorkSpaces* workspaces;
        TopBar* topbar;
        Toolbar* toolbar;

      public:
        MainWindow();
        ~MainWindow();
        void draw();
    };
} // namespace app
#endif // !APP_MAIN_WINDOW_INCLUDED
