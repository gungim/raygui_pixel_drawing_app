#include "workspaces_pannel.hpp"
#include "raygui.h"
#include "raylib.h"
#include "workspace.hpp"
#include "workspaces.hpp"

namespace app {
    WorkSpacesPannel::WorkSpacesPannel() {
        this->offset = {0, 31};
        this->width = GetScreenWidth();
        this->height = 30;
    }
    WorkSpacesPannel::~WorkSpacesPannel() {}
    void WorkSpacesPannel::draw() {
        GuiPanel((Rectangle){this->offset.x, this->offset.y, this->width,
                             this->height},
                 nullptr);
        if (GuiButton(
                (Rectangle){this->width - 4 - 24, this->offset.y + 4, 24, 24},
                "#8#")) {
            WorkSpaces* wps = WorkSpaces::instance();
            WorkSpace* wp = new WorkSpace();
            wps->addPro(wp);
        }
    }
} // namespace app
