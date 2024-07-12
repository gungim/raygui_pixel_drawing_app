#include "raylib.h"
#include <vector>

namespace app {
    struct Template {
        Vector2 size;
        const char* name;
    };
    class Templates {
      private:
        std::vector<Template> tpls;

      public:
        const char* tplsStr;
        Templates();
        ~Templates();
        std::vector<Template> getList();
    };
} // namespace app
