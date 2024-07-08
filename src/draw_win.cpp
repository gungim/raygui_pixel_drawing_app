#include "draw_win.hpp"
#include "raygui.h"
#include "raylib.h"

#include <cstdlib> // Required for: malloc() and free()

Texture2D CreateBG(int width, int height) {
    // Dynamic memory allocation to store pixels data (Color type)
    Color* pixels = (Color*)malloc(width * height * sizeof(Color));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((x / 10 + y / 10) % 2 == 0)
                pixels[y * width + x] = WHITE;
            else
                pixels[y * width + x] = GRAY;
        }
    }

    // Load pixels data into an image structure and create texture
    Image img = {.data = pixels, // We can assign pixels directly to data
                 .width = width,
                 .height = height,
                 .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
                 .mipmaps = 1};

    Texture2D texture = LoadTextureFromImage(img);
    UnloadImage(img);
    return texture;
}

DrawWin::DrawWin() {}
DrawWin::~DrawWin() { UnloadTexture(this->textureBg); }
DrawWin::DrawWin(int w, int h) {
    this->width = w;
    this->height = h;

    this->textureBg = CreateBG(this->width, this->height);

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    this->offset = {(float)(screenWidth - this->width) / 2,
                    (float)(screenHeight - this->height) / 2};
}
void DrawWin::CreateTransBG() {}
void DrawWin::Draw() {
    DrawTexture(this->textureBg, 10, 10, Fade(WHITE, 0.5f));
}

void DrawWin::DrawPixel() {
    Vector2 mousePosition = GetMousePosition();
    Vector2 pixelPositon = {(mousePosition.x - this->offset.x) / this->scale,
                            (mousePosition.y - this->offset.y) / this->scale};

    ImageDrawPixel(&this->image, (int)pixelPositon.x, (int)pixelPositon.y,
                   BLACK);
    UpdateTexture(this->texture, this->image.data);
}
void DrawWin::LoadImg() {}
