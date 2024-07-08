#include "project.hpp"
#include "vector"

#pragma once

class Context {
  private:
    std::vector<Project> projects;

  public:
    const char* pixelFormatTextList[8] = {"CUSTOM",   "GRAYSCALE", "GRAY ALPHA",
                                          "R5G6B5",   "R8G8B8",    "R5G5B5A1",
                                          "R4G4B4A4", "R8G8B8A8"};
    const char* channelsTextList[4] = {"1", "2", "3", "4"};
    const char* bitDepthTextList[3] = {"8", "16", "32"};

    Context();
    ~Context();
    void addProject(Project pr);
    int projectCount();
};
