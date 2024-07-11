#include "raylib.h"
#include <vector>

#pragma once
namespace app {

    class Project {
      private:
        char name[128];
        char locale[256];
        int width;
        int height;
        Texture2D texture;

      public:
        Project();
        ~Project();
        Project(int width, int height, char* name, char* locale, Texture2D tt);
        char* GetName();
        void SetWidth(int w);
        void SetHeight(int h);
        int GetWidth();
        int GetHeight();
        Texture2D GetTexture();
    };

    class Context {
      private:
        static Context* m_instance;

      public:
        static Context* instance() { return m_instance; }

        const char* pixelFormatTextList[8] = {
            "CUSTOM", "GRAYSCALE", "GRAY ALPHA", "R5G6B5",
            "R8G8B8", "R5G5B5A1",  "R4G4B4A4",   "R8G8B8A8"};
        const char* channelsTextList[4] = {"1", "2", "3", "4"};
        const char* bitDepthTextList[3] = {"8", "16", "32"};

        Context();
        ~Context();
    };
} // namespace app
