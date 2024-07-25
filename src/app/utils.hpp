#ifndef APP_UTILS_H_INCLUDED
#define APP_UTILS_H_INCLUDED

/* header information for myfoo.h */

#include "raylib.h"

namespace app {
    typedef struct Vector2i {
        int x; // Vector x component
        int y; // Vector y component
    } Vector2i;

    namespace utils {
        Image CreateTransparentImage(int width, int height);
        Vector2 MousePositionOnTexture(Vector2 texturePos, float scale,
                                       Vector2 mousePos);
    } // namespace utils
} // namespace app
#endif
