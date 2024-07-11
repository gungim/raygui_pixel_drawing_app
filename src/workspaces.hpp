#include <vector>
namespace app {
    class WorkSpace;
    class WorkSpacesPannel;
    class ImportFile;

    class WorkSpaces {
      private:
        std::vector<WorkSpace*> workspaces;
        WorkSpace* activeWorkspace;
        WorkSpacesPannel* workSpacesPannel;
        ImportFile* importFileWindow;
        static WorkSpaces* m_instance;

      public:
        WorkSpaces();
        ~WorkSpaces();
        static WorkSpaces* instance() { return m_instance; }
        void draw();
        void addPro(WorkSpace* wp);
        void add(int width, int height, char* name);
        void setCurrent(int index);
    };
} // namespace app
