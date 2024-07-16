#include "toolbar.hpp"
#include "raygui.h"

#include "iostream"

namespace app {
    Toolbar* Toolbar::m_instance = nullptr;
    Toolbar::Toolbar() {
        this->offset = {0, 61};
        this->size = {32, (LIST_ITEMS_HEIGHT + 15) * MAX_TOOL};
        this->scrollIndex = 0;
        this->selectedTool = 0;
        m_instance = this;
    };

    Toolbar::~Toolbar() { delete m_instance; };
    void Toolbar::draw() {
        GuiListView((Rectangle){this->offset.x, this->offset.y, this->size.x,
                                this->size.y},
                    TextJoin(guiControlText, MAX_TOOL, ";"), &this->scrollIndex,
                    &this->selectedTool);
    }
    int Toolbar::getCurrentTool() { return this->selectedTool; }
} // namespace app
