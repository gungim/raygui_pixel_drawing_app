#include "raylib.h"

namespace app {
    class Context;
    static const int MAX_TOOL = 11;
    static const char* guiControlText[MAX_TOOL] = {
        "#108#", // Select area
        "#19#",  // Hand
        "#27#",  // COlor picker,
        "#28#",  // Easer
        "#29#",  // COlor bucket
        "#67#",  // Move
        "#23#",  // Pencil
        "#133#", // Draw Square
        "#192#", // Draw line
        "#135#", // Draw circle
        "#220#", // Draw elipse
    };
    typedef enum {
        TOOL_SELECT = 0,
        TOOL_HAND,
        TOOL_COLOR_PICKER,
        TOOL_EASER,
        TOOL_COLOR_BUCKET,
        TOOL_MOVE,
        TOOL_PENCIL,
        TOOL_DRAW_SQUARE,
        TOOL_DRAW_LINE,
        TOOL_DRAW_CIRCLE,
        TOOL_DRAW_ELLIPSE,
        DRAW_MODE
    } TOOL_TYPE; // namespace app
    class Toolbar {
      private:
        Vector2 offset;
        Vector2 size;
        int selectedTool;
        int scrollIndex;
        int outlineMode;

        static Toolbar* m_instance;

      public:
        Toolbar();
        ~Toolbar();
        void draw();
        int getCurrentTool();
        bool getOutlineMode();
        static Toolbar* instance() { return m_instance; }
    };
} // namespace app
