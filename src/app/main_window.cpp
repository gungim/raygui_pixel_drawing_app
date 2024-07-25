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
    MainWindow::~MainWindow() {
        delete this->workspaces;
        delete this->toolbar;
        delete this->topbar;
    }
    void MainWindow::draw() {
        this->workspaces->draw();
        this->topbar->draw();
        this->toolbar->draw();
    }
} // namespace app
