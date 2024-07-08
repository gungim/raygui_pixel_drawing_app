#include "raylib.h"

class DrawWin {
  private:
    int width;
    int height;
    Texture texture;

    Image image;
    float scale;
    Vector2 offset;

  protected:
    Texture2D textureBg;

  public:
    DrawWin();
    DrawWin(int w, int h);
    ~DrawWin();
    void Draw();
    void DrawPixel();
    void LoadImg();
    void CreateTransBG();
};
