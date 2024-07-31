#include "workspaces.hpp"
#include "app/utils.hpp"
#include "import_file.hpp"
#include "raylib.h"
#include "toolbar.hpp"
#include "workspace.hpp"

#include "iostream"
#include <cstring>

namespace app {
    WorkSpaces* WorkSpaces::m_instance = nullptr;
    WorkSpaces::WorkSpaces() {
        m_instance = this;
        this->workspaces = {};
        this->activeWorkspace = nullptr;
        this->importFileWindow = new ImportFile();

        this->allocateTablist();
    }
    void WorkSpaces::allocateTablist() {
        this->tabList = new char*[this->tabCount];
        for (int i = 0; i < this->tabCount; ++i) {
            this->tabList[i] = new char[this->tabCount];
            std::memset(this->tabList[i], 0,
                        20); // Initialize with null characters
        }
    }

    // Helper function to deallocate memory
    void WorkSpaces::deallocateTablist() {
        for (int i = 0; i < this->tabCount; ++i) {
            delete[] this->tabList[i];
        }
        delete[] this->tabList;
    }
    WorkSpaces::~WorkSpaces() {
        this->workspaces.clear();
        delete m_instance;
        delete this->activeWorkspace;

        this->deallocateTablist();
    }
    void WorkSpaces::draw() {
        if (this->activeWorkspace) {
            this->activeWorkspace->draw();
        }
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
    void WorkSpaces::add(Vector2i n_size, char* name) {
        WorkSpace* wp = new WorkSpace(n_size);
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
