#ifndef APP_WPS_H_INCLUDED
#define APP_WPS_H_INCLUDED

#include "raygui.h"
#include "utils.hpp"
#include <vector>

namespace app {
    using namespace utils;
    class WorkSpace;
    class WorkSpacesPannel;
    class ImportFile;
    class Toolbar;

    class WorkSpaces {
      private:
        std::vector<WorkSpace*> workspaces;
        WorkSpace* activeWorkspace;
        int activeWorkspaceIndex;
        WorkSpacesPannel* workSpacesPannel;

        ImportFile* importFileWindow;
        static WorkSpaces* m_instance;
        char** tabList;
        int tabCount;
        void allocateTablist();
        void deallocateTablist();

      public:
        WorkSpaces();
        ~WorkSpaces();
        static WorkSpaces* instance() { return m_instance; }
        void draw();
        void addPro(WorkSpace* wp);
        void add(Vector2i n_size, char* name);
        void setCurrent(int index);
        void resize(int width, int height);
        WorkSpace* getActive();
        Vector2i getCurrentSize();
    };
} // namespace app
#endif // !APP_WPS_H_INCLUDED
