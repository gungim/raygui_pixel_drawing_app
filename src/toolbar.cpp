#include "toolbar.hpp"
#include "app_utils.hpp"
#include "raygui.h"
#include "raylib.h"

namespace app {
    Toolbar* Toolbar::m_instance = nullptr;
    Toolbar::Toolbar() {
        this->offset = {2, 32};
        this->size = {32, ((float)GuiGetStyle(LISTVIEW, LIST_ITEMS_HEIGHT) +
                           GuiGetStyle(LISTVIEW, LIST_ITEMS_SPACING) +
                           GuiGetStyle(LISTVIEW, BORDER_WIDTH)) *
                              MAX_TOOL};
        this->scrollIndex = 0;

        this->selectedTool = 0;
        this->outlineMode = 0;
        m_instance = this;
    };

    Toolbar::~Toolbar() { delete m_instance; };
    void Toolbar::draw() {
        GuiListView((Rectangle){this->offset.x, this->offset.y, this->size.x,
                                this->size.y},
                    TextJoin(guiControlText, MAX_TOOL, ";"), &this->scrollIndex,
                    &this->selectedTool);

        CListItem("#221#", {(int)this->offset.x, (int)this->size.y + 32 + 2},
                  {32, 32}, this->outlineMode);
    }
    int Toolbar::getCurrentTool() { return this->selectedTool; }
    bool Toolbar::getOutlineMode() { return this->outlineMode; }
} // namespace app
