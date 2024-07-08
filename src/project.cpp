#include "project.hpp"
#include "cstring"

Project::Project() {}
Project::~Project() {}
Project::Project(int width, int height, char* name, char* imgLocale,
                 char* locale) {
    this->width = width;
    this->height = height;
    std::strcpy(this->name, name);
    std::strcpy(this->imgLocale, imgLocale);
    std::strcpy(this->locale, locale);
}

char* Project::getName() { return this->name; }
void Project::setWidth(int w) { this->width = w; }
void Project::setHeight(int h) { this->height = h; }
