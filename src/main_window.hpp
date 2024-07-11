namespace app {
    class Context;
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
        void draw(Context* context);
    };
} // namespace app
