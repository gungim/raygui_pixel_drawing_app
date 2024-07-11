#include "workspace.hpp"
#include "app_utils.hpp"
#include "raygui.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "iostream"
#include <cmath>

namespace app {
    WorkSpace::WorkSpace() {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();

        this->camera = {0};
        this->camera.zoom = 1.0f;

        this->texture = {0};
        this->scale = 3;
        this->rotate = 0;

        this->width = 32;
        this->height = 32;

        this->offset = {(float)(screenW - this->width) / 2,
                        (float)(screenH - this->height) / 2};
        this->boxOffset = this->offset;

        Image transIMG = CreateTransparentImage(screenW, screenH);
        this->transBG = LoadTextureFromImage(transIMG);
        UnloadImage(transIMG);
    }
    WorkSpace::WorkSpace(int w, int h, char* n) {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();

        this->camera = {0};
        this->camera.zoom = 1.0f;

        this->texture = {0};
        this->scale = 3;
        this->rotate = 0;

        this->width = w;
        this->height = h;

        this->offset = {(float)(screenW - this->width) / 2,
                        (float)(screenH - this->height) / 2};
        this->boxOffset = this->offset;

        Image transIMG = CreateTransparentImage(screenW, screenH);
        this->transBG = LoadTextureFromImage(transIMG);
        UnloadImage(transIMG);
    }
    WorkSpace::~WorkSpace() {
        UnloadTexture(this->transBG);
        UnloadTexture(this->texture);
    }
    void WorkSpace::setupTexture() {}
    void WorkSpace::draw() {

        this->zoom();
        this->move();

        BeginMode2D(this->camera);
        if (this->texture.id != 0) {
            DrawTextureEx(this->texture, this->offset, this->rotate,
                          this->scale, BLANK);
        }
        DrawTextureRec(this->transBG,
                       (Rectangle){this->offset.x, this->offset.y,
                                   (float)this->width, (float)this->height},
                       this->boxOffset, RED);

        EndMode2D();
    }
    void WorkSpace::zoom() {
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos =
                GetScreenToWorld2D(GetMousePosition(), this->camera);

            // Set the offset to where the mouse is
            this->camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world
            // space point under the cursor to the screen space point under
            // the cursor at any zoom
            this->camera.target = mouseWorldPos;

            // Zoom increment
            float scaleFactor = 1.0f + (0.25f * fabsf(wheel));
            if (wheel < 0)
                scaleFactor = 1.0f / scaleFactor;
            this->camera.zoom =
                Clamp(this->camera.zoom * scaleFactor, 0.125f, 64.0f);
        }
    }
    void WorkSpace::move() {
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f / this->camera.zoom);
            this->camera.target = Vector2Add(this->camera.target, delta);
        }
    }
    void WorkSpace::close() {};

} // namespace app
