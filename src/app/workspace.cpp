#include "workspace.hpp"
#include "../tool/tool.hpp"
#include "layer_pannel.hpp"
#include "raymath.h"
#include "rdrawing.h"
#include "rlgl.h"
#include "toolbar.hpp"

#include "iostream"
#include <cmath>
#include <cstdlib>

namespace app {
    WorkSpace::WorkSpace(Vector2i s) {
        this->color = RED;
        this->saved = false;
        this->thick = 2;
        this->l_pannel = new LayerPannel(this->config);
        this->config->size = s;
    }
    WorkSpace::~WorkSpace() {
        delete this->config;
        delete this->l_pannel;
        UnloadTexture(this->transBG);
        UnloadTexture(this->texture);
        UnloadImage(this->image);
    }
    void WorkSpace::resize(Vector2i s) {
        this->config->size = s;
        this->l_pannel->resize();
    }
    void WorkSpace::loadTexture(Image img) {
        this->texture = LoadTextureFromImage(img);
    }
    void WorkSpace::initialize() {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();

        this->camera.zoom = 1.0f;
        Vector2i size = this->config->size;

        this->config->offset = {(float)(screenW - size.x) / 2,
                                (float)(screenH - size.y) / 2};

        this->image = GenImageColor(size.x, size.y, BLANK);
        if (this->image.data != NULL) {
            this->texture = LoadTextureFromImage(this->image);
        }

        Image transIMG = utils::CreateTransparentImage(screenW, screenH);
        this->transBG = LoadTextureFromImage(transIMG);
        UnloadImage(transIMG);
    }
    void WorkSpace::draw() {
        this->control();

        BeginMode2D(this->camera);
        DrawTextureRec(this->transBG,
                       (Rectangle){this->config->offset.x,
                                   this->config->offset.y,
                                   (float)this->config->size.x,
                                   (float)this->config->size.y},
                       this->config->offset, Fade(WHITE, 0.5f));
        DrawTextureV(this->texture, this->config->offset, Fade(WHITE, 1.f));

        EndMode2D();
        this->l_pannel->draw();
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
                        this->paintPixel(this->startPoint, this->color);
                        break;
                    }
                    case TOOL_EASER: {
                        this->paintPixel(this->startPoint, BLANK);
                    }
                }
            }
        } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            int currentTool = Toolbar::instance()->getCurrentTool();
            this->endPoint = GetPixelPositionInWorld(GetMousePosition());
            if (IsKeyDown(KEY_LEFT_SHIFT)) {
                switch (currentTool) {
                    case TOOL_PENCIL: {
                        this->paintLine(this->startPoint, this->endPoint,
                                        this->color);
                        break;
                    }
                    case TOOL_DRAW_LINE: {
                        this->paintLineHV(this->color);
                        break;
                    }
                    case TOOL_EASER: {
                        this->paintLineHV(BLANK);
                        break;
                    }
                    case TOOL_DRAW_CIRCLE: {
                        float radius = Vector2Distance(
                            {(float)this->startPoint.x,
                             (float)this->startPoint.y},
                            {(float)this->endPoint.x, (float)this->endPoint.y});
                        this->paintCircle(this->startPoint, radius);
                        break;
                    }
                }
            } else {
                switch (currentTool) {
                    case TOOL_DRAW_LINE: {
                        this->paintLine(this->startPoint, this->endPoint,
                                        this->color);
                        break;
                    }
                    case TOOL_DRAW_CIRCLE: {
                        float radiusX = this->endPoint.x - this->startPoint.x;
                        float radiusY = this->endPoint.y - this->startPoint.y;
                        this->paintEllipse(this->startPoint, abs(radiusX),
                                           abs(radiusY));
                    }
                    case TOOL_EASER: {
                        this->paintLine(this->startPoint, this->endPoint,
                                        BLANK);
                        break;
                    }
                }
            }
        }
    }
    void WorkSpace::paintPixel(Vector2i point, Color cl) {
        ImageDrawPointEx(&this->image, point.x, point.y, this->thick, cl);
        UpdateTexture(this->texture, this->image.data);
    }
    void WorkSpace::paintLine(Vector2i start, Vector2i end, Color cl) {
        ImageDrawLineEx2(&this->image, start.x, start.y, end.x, end.y,
                         this->thick, cl);
        UpdateTexture(this->texture, this->image.data);
    }
    void WorkSpace::paintLineHV(Color cl) {
        Vector2 normalFromStartPoint = Vector2Subtract(
            {(float)this->endPoint.x, (float)this->endPoint.y},
            {(float)this->startPoint.x, (float)this->startPoint.y});

        Vector2i end = {0, 0};
        if (abs(normalFromStartPoint.x) >= abs(normalFromStartPoint.y)) {
            end.x = this->endPoint.x;
            end.y = this->startPoint.y;
        } else {
            end.x = this->startPoint.x;
            end.y = this->endPoint.y;
        }

        this->paintLine(this->startPoint, end, cl);
    }

    void WorkSpace::paintCircle(Vector2i centerPoint, int radius) {
        if (Toolbar::instance()->getOutlineMode()) {
            ImageDrawCircleEx(&this->image, centerPoint.x, centerPoint.y,
                              radius, this->thick, this->color);
        } else {
            ImageDrawCircle(&this->image, centerPoint.x, centerPoint.y, radius,
                            this->color);
        }
        UpdateTexture(this->texture, this->image.data);
    }
    void WorkSpace::paintEllipse(Vector2i centerPoint, int radiusX,
                                 int radiusY) {
        if (Toolbar::instance()->getOutlineMode()) {
            ImageDrawEllipseEx(&this->image, centerPoint.x, centerPoint.y,
                               radiusX, radiusY, this->thick, this->color);
        } else {
            ImageFillEllipseEx(&this->image, centerPoint.x, centerPoint.y,
                               radiusX, radiusY, this->color);
        }
        UpdateTexture(this->texture, this->image.data);
    }

    void WorkSpace::close() {};
    Vector2i WorkSpace::getSize() { return this->config->size; }

    Vector2i WorkSpace::GetPixelPositionInWorld(Vector2 postion) {
        Vector2 mouseInWorkPosition = GetScreenToWorld2D(postion, this->camera);
        Vector2 offset = this->config->offset;
        return {(int)mouseInWorkPosition.x - (int)offset.x,
                (int)mouseInWorkPosition.y - (int)offset.y};
    }
} // namespace app
