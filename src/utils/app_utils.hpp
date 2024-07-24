#ifndef APP_UTILS
#define APP_UTILS

/* header information for myfoo.h */

#include "raylib.h"

namespace utils {
    typedef struct Vector2i {
        int x; // Vector x component
        int y; // Vector y component
    } Vector2i;

    Image CreateTransparentImage(int width, int height);
    Vector2 MousePositionOnTexture(Vector2 texturePos, float scale,
                                   Vector2 mousePos);
    int CListItem(const char* text, Vector2i pos, Vector2i size, int* active);
    int CGuiTabBar(Rectangle bounds, const char** tabNames, int* active,
                   int count);
} // namespace utils
#endif
