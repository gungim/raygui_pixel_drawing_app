/*******************************************************************************************
 *
 *   raylib [core] example - window scale letterbox (and virtual mouse)
 *
 *   This example has been created using raylib 2.5 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Example contributed by Anata (@anatagawa) and reviewed by Ramon Santamaria
 *(@raysan5)
 *
 *   Copyright (c) 2019 Anata (@anatagawa) and Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/
#include "app/app.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    app::App* newApp = new app::App();
    newApp->init();
    newApp->run();
    return 0;
}
