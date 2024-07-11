#include "main_window.hpp"
#include "toolbar.hpp"
#include "topbar.hpp"
#include "workspaces.hpp"

namespace app {
    MainWindow::MainWindow() {
        this->workspaces = new WorkSpaces();
        this->topbar = new TopBar();
        this->toolbar = new Toolbar();
    }
    MainWindow::~MainWindow() {}
    void MainWindow::draw(Context* context) {
        this->workspaces->draw();
        topbar->draw(context, (Vector2){0, 0});
    }
} // namespace app
