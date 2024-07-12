#include "workspaces.hpp"
#include "import_file.hpp"
#include "raylib.h"
#include "workspace.hpp"
#include "workspaces_pannel.hpp"

#include "iostream"

namespace app {
    WorkSpaces* WorkSpaces::m_instance = nullptr;
    WorkSpaces::WorkSpaces() {
        m_instance = this;
        this->workspaces = {};
        this->activeWorkspace = nullptr;
        this->workSpacesPannel = new WorkSpacesPannel();
        this->importFileWindow = new ImportFile();
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
        this->workSpacesPannel->draw();
    }
    void WorkSpaces::setCurrent(int index) {
        if (index < this->workspaces.size()) {
            this->activeWorkspace = this->workspaces.at(index);
        }
    }
    void WorkSpaces::addPro(WorkSpace* wp) {
        wp->initialize();
        this->workspaces.push_back(wp);
        this->activeWorkspace = wp;
        std::cout << "Add workspace success" << std::endl;
    }
    void WorkSpaces::add(int w, int h, char* name) {
        WorkSpace* wp = new WorkSpace();
        wp->reSize({(float)w, (float)h});
        wp->initialize();
        this->workspaces.push_back(wp);
        this->activeWorkspace = wp;
        std::cout << "Add new project";
    }
    WorkSpace* WorkSpaces::getActive() { return this->activeWorkspace; }
    Vector2 WorkSpaces::getCurrentSize() {
        if (this->activeWorkspace) {
            return this->activeWorkspace->getSize();
        } else {
            return (Vector2){0, 0};
        }
    }
    void WorkSpaces::resize(int w, int h) {
        this->activeWorkspace->reSize({(float)w, (float)h});
    }
} // namespace app
