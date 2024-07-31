#ifndef APP_TEMPLATE_H_INCLUDED
#define APP_TEMPLATE_H_INCLUDED

#include "utils.hpp"
#include <vector>

namespace app {
    struct Template {
        Vector2i size;
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
#endif // !APP_TEMPLATE_H_INCLUDED
