#include "workspaces.hpp"
#include "import_file.hpp"
#include "raygui.h"
#include "raylib.h"
#include "toolbar.hpp"
#include "workspace.hpp"
#include "workspaces_pannel.hpp"

#include "iostream"
#include <cstring>

namespace app {
    WorkSpaces* WorkSpaces::m_instance = nullptr;
    WorkSpaces::WorkSpaces() {
        m_instance = this;
        this->workspaces = {};
        this->activeWorkspace = nullptr;
        this->workSpacesPannel = new WorkSpacesPannel();
        this->importFileWindow = new ImportFile();
        // char** temp = new char*[2];
        // strcpy(temp[0], "dev 1");
        // strcpy(temp[1], "dev 2");
        // this->tabList = (const char**)temp;
    }
    WorkSpaces::~WorkSpaces() {
        this->workspaces.clear();
        delete m_instance;
        delete this->activeWorkspace;
        delete this->workSpacesPannel;
    }
    void WorkSpaces::draw() {
        if (this->activeWorkspace) {
            this->activeWorkspace->draw();
        }
        // GuiTabBar((Rectangle){0, 32, (float)GetScreenWidth(), 32},
                  // this->tabList, 10, &this->activeWorkspaceIndex);
    }
    void WorkSpaces::setCurrent(int index) {
        if (index < this->workspaces.size()) {
            this->activeWorkspace = this->workspaces.at(index);
            this->activeWorkspaceIndex = index;
        }
    }
    void WorkSpaces::addPro(WorkSpace* wp) {
        wp->initialize();
        this->workspaces.push_back(wp);
        this->activeWorkspace = wp;
        std::cout << "Add workspace success" << std::endl;
    }
    void WorkSpaces::add(int w, int h, char* name) {
        WorkSpace* wp = new WorkSpace({w, h});
        wp->initialize();
        this->workspaces.push_back(wp);
        this->activeWorkspace = wp;
        std::cout << "Add new project";
    }
    WorkSpace* WorkSpaces::getActive() { return this->activeWorkspace; }
    Vector2i WorkSpaces::getCurrentSize() {
        if (this->activeWorkspace) {
            return this->activeWorkspace->getSize();
        } else {
            return {0, 0};
        }
    }
    void WorkSpaces::resize(int w, int h) {
        this->activeWorkspace->resize({w, h});
    }
} // namespace app
