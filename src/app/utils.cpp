#include "utils.hpp"
#include <cstdlib> // Required for: malloc() and free()

namespace app {

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
            Image img = {.data =
                             pixels, // We can assign pixels directly to data
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

    } // namespace utils
} // namespace app
