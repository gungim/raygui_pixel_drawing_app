#include "utils/app_utils.hpp"
#include <vector>

using namespace utils;
namespace app {
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
        const char** tabList;

      public:
        WorkSpaces();
        ~WorkSpaces();
        static WorkSpaces* instance() { return m_instance; }
        void draw();
        void addPro(WorkSpace* wp);
        void add(int width, int height, char* name);
        void setCurrent(int index);
        void resize(int width, int height);
        WorkSpace* getActive();
        utils::Vector2i getCurrentSize();
    };
} // namespace app
