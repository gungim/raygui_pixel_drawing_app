#include "win_widget.hpp"
namespace ui {
    void WinWidget::open() {
        this->isOpen = true;

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        this->offset = {(float)(screenWidth - this->size.x) / 2,
                        (float)(screenHeight - this->size.y) / 2};
    }
} // namespace ui
