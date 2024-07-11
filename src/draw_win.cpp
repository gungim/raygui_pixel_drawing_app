#include "draw_win.hpp"
#include "app_utils.hpp"
#include "context.hpp"
#include "raygui.h"
#include "raylib.h"

namespace app {
    DrawWin::DrawWin() {
        Project* pr = new Project();
        this->project = pr;
        this->width = pr->GetWidth();
        this->height = pr->GetHeight();

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        this->offset = {(float)(screenWidth - this->width) / 2,
                        (float)(screenHeight - this->height) / 2};
    }
    DrawWin::~DrawWin() {
        UnloadTexture(this->textureBg);
        UnloadTexture(this->texture);
    }
    void DrawWin::Draw() {
        DrawTexture(this->textureBg, 10, 10, Fade(WHITE, 0.5f));
        DrawTexture(this->texture, this->offset.x, this->offset.y, BLANK);
    }

    void DrawWin::DrawPixel() {
        Vector2 mousePosition = GetMousePosition();
        Vector2 pixelPositon = {
            (mousePosition.x - this->offset.x) / this->scale,
            (mousePosition.y - this->offset.y) / this->scale};

        ImageDrawPixel(&this->image, (int)pixelPositon.x, (int)pixelPositon.y,
                       BLACK);
        UpdateTexture(this->texture, this->image.data);
    }
    void DrawWin::LoadProject() {
        Texture2D tt = this->project->GetTexture();
        if (tt.id) {
            this->texture = tt;
        }
    }
} // namespace app
