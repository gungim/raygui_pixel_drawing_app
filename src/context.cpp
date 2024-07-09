#include "context.hpp"

namespace app {

    Context::Context() {
        this->project = Project();
        this->projects = {};
        this->projectsName = {};
    }
    Context::~Context() {}

    void Context::AddProject(Project pr) {
        // this->projects.push_back(pr);
        // this->projectsName.push_back(pr.GetName());
        this->project = pr;
    }
    void Context::UpdateProject(Project pr, int index) {

    };

    int Context::ProjectCount() { return this->projects.size(); }

    Project::Project() {
        this->width = 32;
        this->height = 32;
        std::strcpy(this->name, "Untitled");
        std::strcpy(this->locale, "\0");
        this->texture = {0};
    }
    Project::~Project() {}
    Project::Project(int width, int height, char* name, char* locale,
                     Texture2D tt) {
        this->width = width;
        this->height = height;
        std::strcpy(this->name, name);
        std::strcpy(this->locale, locale);
        this->texture = tt;
    }

    char* Project::GetName() { return this->name; }
    void Project::SetWidth(int w) { this->width = w; }
    void Project::SetHeight(int h) { this->height = h; }
    int Project::GetWidth() { return this->width; }
    int Project::GetHeight() { return this->height; }
    Texture2D Project::GetTexture() { return this->texture; }
} // namespace app
