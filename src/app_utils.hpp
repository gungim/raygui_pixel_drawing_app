#include "raylib.h"

namespace app {
    typedef struct Vector2i {
        int x; // Vector x component
        int y; // Vector y component
    } Vector2i;

    Image CreateTransparentImage(int width, int height);
    Vector2 MousePositionOnTexture(Vector2 texturePos, float scale,
                                   Vector2 mousePos);
    int CListItem(const char* text, Vector2i pos, Vector2i size, int& active);
} // namespace app
