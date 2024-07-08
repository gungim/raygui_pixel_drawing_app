#include "context.hpp"

Context::Context() { this->projects = {}; }
Context::~Context() {}
void Context::addProject(Project pr) { this->projects.push_back(pr); }
int Context::projectCount() { return this->projects.size(); }
