#include "workspace.hpp"
#include "app_utils.hpp"
#include "raygui.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "iostream"
#include <cmath>

namespace app {
    WorkSpace::WorkSpace() {}
    WorkSpace::~WorkSpace() {
        delete this->name;
        UnloadTexture(this->transBG);
        UnloadTexture(this->texture);
        UnloadImage(this->image);
    }
    void WorkSpace::reSize(Vector2 s) { this->size = s; }
    void WorkSpace::loadTexture(Image img) {
        this->texture = LoadTextureFromImage(img);
    }
    void WorkSpace::initialize() {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();

        this->camera.zoom = 1.0f;

        this->offset = {(float)(screenW - this->size.x) / 2,
                        (float)(screenH - this->size.y) / 2};
        this->boxOffset = this->offset;

        this->image =
            GenImageColor(this->boxOffset.x, this->boxOffset.y, BLANK);
        if (this->image.data != NULL) {
            this->texture = LoadTextureFromImage(this->image);
        }

        Image transIMG = CreateTransparentImage(screenW, screenH);
        this->transBG = LoadTextureFromImage(transIMG);
        UnloadImage(transIMG);
    }
    void WorkSpace::draw() {

        this->zoom();
        this->move();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 position =
                GetScreenToWorld2D(GetMousePosition(), this->camera);
            Vector2 pixelPos = {position.x - this->boxOffset.x,
                                position.y - this->boxOffset.y};
            ImageDrawPixel(&this->image, (int)pixelPos.x, (int)pixelPos.y, RED);
            UpdateTexture(this->texture, this->image.data);
        }

        BeginMode2D(this->camera);
        DrawTextureRec(this->transBG,
                       (Rectangle){this->offset.x, this->offset.y, this->size.x,
                                   this->size.y},
                       this->boxOffset, Fade(WHITE, 0.5f));

        DrawTexture(this->texture, this->boxOffset.x, this->boxOffset.y,
                    Fade(WHITE, 1.f));

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
    Vector2 WorkSpace::getSize() { return this->size; }

} // namespace app
