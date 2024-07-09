#include "app_utils.hpp"
#include "raylib.h"

#include <cstdlib> // Required for: malloc() and free()
namespace app {

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
} // namespace app
