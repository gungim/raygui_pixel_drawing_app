#include "toolbar.hpp"
#include "raygui.h"
#include "raylib.h"

namespace app {

    Toolbar* Toolbar::m_instance = nullptr;
    Toolbar::Toolbar() {
        this->offset = {2, 64};
        this->size = {32, 32 * (MAX_TOOL)};
        this->scrollIndex = 0;

        this->selectedTool = 0;
        this->outlineMode = false;
        m_instance = this;
    };

    Toolbar::~Toolbar() { delete m_instance; };
    void Toolbar::draw() {
        GuiListView((Rectangle){this->offset.x, this->offset.y, this->size.x,
                                this->size.y},
                    TextJoin(guiControlText, MAX_TOOL, ";"), &this->scrollIndex,
                    &this->selectedTool);

        GuiToggle(
            (Rectangle){this->offset.x, this->size.y + this->offset.y + 2},
            "#221#", &this->outlineMode);
    }
    int Toolbar::getCurrentTool() { return this->selectedTool; }
    bool Toolbar::getOutlineMode() { return this->outlineMode; }
} // namespace app
