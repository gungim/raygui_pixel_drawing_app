#include "workspace.hpp"
#include "raygui.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include "tool/tool.hpp"
#include "toolbar.hpp"

#include "iostream"
#include <cmath>
#include <cstdlib>

namespace app {
    WorkSpace::WorkSpace() { this->color = RED; }
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
        this->control();
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
        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f / this->camera.zoom);
        this->camera.target = Vector2Add(this->camera.target, delta);
    }
    void WorkSpace::control() {
        this->zoom();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int currentTool = Toolbar::instance()->getCurrentTool();
            this->startPoint = GetPixelPositionInWorld(GetMousePosition());
            if (not IsKeyDown(KEY_LEFT_SHIFT)) {
                switch (currentTool) {
                    case TOOL_HAND: {
                        this->move();
                        break;
                    }
                    case TOOL_PENCIL: {
                        this->paintPixel(this->startPoint);
                        break;
                    }
                }
            }
        } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            int currentTool = Toolbar::instance()->getCurrentTool();
            this->endPoint = GetPixelPositionInWorld(GetMousePosition());
            if (IsKeyDown(KEY_LEFT_SHIFT)) {
                switch (currentTool) {
                    case TOOL_PENCIL: {
                        this->paintLine(this->startPoint, this->endPoint);
                        break;
                    }
                    case TOOL_DRAW_LINE: {
                        Vector2 normalFromStartPoint = Vector2Subtract(
                            {(float)this->endPoint.x, (float)this->endPoint.y},
                            {(float)this->startPoint.x,
                             (float)this->startPoint.y});

                        Vector2i end = {0, 0};
                        if (abs(normalFromStartPoint.x) >=
                            abs(normalFromStartPoint.y)) {
                            end.x = this->endPoint.x;
                            end.y = this->startPoint.y;
                        } else {
                            end.x = this->startPoint.x;
                            end.y = this->endPoint.y;
                        }

                        std::cout << end.x << ", " << end.y << std::endl;
                        this->paintLine(this->startPoint, end);
                        break;
                    }
                }
            } else {
                switch (currentTool) {
                    case TOOL_DRAW_LINE: {
                        this->paintLine(this->startPoint, this->endPoint);
                        break;
                    }
                }
            }
        }
    }
    void WorkSpace::paintPixel(Vector2i point) {
        ImageDrawPixel(&this->image, point.x, point.y, this->color);
        UpdateTexture(this->texture, this->image.data);
    }
    void WorkSpace::paintLine(Vector2i start, Vector2i end) {
        ImageDrawLine(&this->image, start.x, start.y, end.x, end.y,
                      this->color);
        UpdateTexture(this->texture, this->image.data);
    }

    void WorkSpace::endPaint() {}
    void WorkSpace::paintCircle(bool circle) {
        Vector2 currentPoint = GetMousePosition();
        if (IsKeyPressed(KEY_LEFT_SHIFT)) {
            ImageDrawCircle(&this->image, (int)currentPoint.x,
                            (int)currentPoint.y, 30, this->color);
        } else {
        }
    }

    void WorkSpace::close() {};
    Vector2 WorkSpace::getSize() { return this->size; }

    Vector2i WorkSpace::GetPixelPositionInWorld(Vector2 postion) {
        Vector2 mouseInWorkPosition = GetScreenToWorld2D(postion, this->camera);
        return {(int)mouseInWorkPosition.x - (int)this->boxOffset.x,
                (int)mouseInWorkPosition.y - (int)this->boxOffset.y};
    }
} // namespace app
