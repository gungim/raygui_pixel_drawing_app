#include "app_utils.hpp"
#include <cstdlib> // Required for: malloc() and free()

#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // Required for: IMGUI controls

#undef RAYGUI_IMPLEMENTATION // Avoid including raygui implementation again

#include "iostream"

namespace utils {
    Image CreateTransparentImage(int width, int height) {

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
        return img;
    }
    Vector2 MousePositionOnTexture(Vector2 texturePos, float scale,
                                   Vector2 mousePos) {
        Vector2 pixelPositon = {(mousePos.x - texturePos.x) / scale,
                                (mousePos.y - texturePos.y) / scale};
        return pixelPositon;
    }
    Vector2 PixelPositonToGlobalPositon(Vector2 pixelPos, float scale) {
        return {0, 0};
    }
    Vector2 ScaleTextureWithMouse() {
        Vector2 texturePos = {0, 0};
        return texturePos;
    }

    int CListItem(const char* text, Vector2i pos, Vector2i size, int* active) {
        int result = 0;
        GuiState state = guiState;

        Rectangle itemBounds = {0};
        itemBounds.x = pos.x;
        itemBounds.y = pos.y;
        itemBounds.width = size.x;
        itemBounds.height = size.y;
        bool focus = 0;

        if (state == STATE_DISABLED) {
            if (*active) {
                DrawRectangleLinesEx(
                    itemBounds, GuiGetStyle(LISTVIEW, BORDER_WIDTH),
                    GetColor(GuiGetStyle(LISTVIEW, BORDER_COLOR_DISABLED)));
                GuiDrawText(
                    text, itemBounds, GuiGetStyle(LISTVIEW, TEXT_ALIGNMENT),
                    GetColor(GuiGetStyle(LISTVIEW, TEXT_COLOR_DISABLED)));
            }
        } else {
            if (CheckCollisionPointRec(GetMousePosition(), itemBounds)) {
                focus = true;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (*active == 0) {
                        *active = 1;
                    } else {
                        *active = 0;
                    }
                }
            } else {
                focus = false;
            }

            if (*active) {

                GuiDrawRectangle(
                    itemBounds, GuiGetStyle(LISTVIEW, BORDER_WIDTH),
                    GetColor(GuiGetStyle(LISTVIEW, BORDER_COLOR_PRESSED)),
                    GetColor(GuiGetStyle(LISTVIEW, BASE_COLOR_PRESSED)));
                GuiDrawText(
                    text, itemBounds, GuiGetStyle(LISTVIEW, TEXT_ALIGNMENT),
                    GetColor(GuiGetStyle(LISTVIEW, TEXT_COLOR_PRESSED)));
            } else if (focus) {
                GuiDrawRectangle(
                    itemBounds, GuiGetStyle(LISTVIEW, BORDER_WIDTH),
                    GetColor(GuiGetStyle(LISTVIEW, BORDER_COLOR_FOCUSED)),
                    GetColor(GuiGetStyle(LISTVIEW, BASE_COLOR_FOCUSED)));
                GuiDrawText(
                    text, itemBounds, GuiGetStyle(LISTVIEW, TEXT_ALIGNMENT),
                    GetColor(GuiGetStyle(LISTVIEW, TEXT_COLOR_FOCUSED)));
            } else {
                GuiDrawText(text, itemBounds,
                            GuiGetStyle(LISTVIEW, TEXT_ALIGNMENT),
                            GetColor(GuiGetStyle(LISTVIEW, TEXT_COLOR_NORMAL)));
            }
        }

        return result;
    }
    int CGuiTabBar(Rectangle bounds, const char** tabNames, int* active,
                  int count) {
        // This function should render the tab bar and return the index of the
        // active tab
        int result = 0;
        for (int i = 0; i < count; i++) {
            if (GuiButton((Rectangle){bounds.x + i * (bounds.width / count),
                                      bounds.y, bounds.width / count,
                                      bounds.height},
                          tabNames[i])) {
                *active = i;
            }
        }

        return result;
    }

} // namespace utils
