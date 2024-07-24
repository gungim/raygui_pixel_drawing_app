include_directories(.)


set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_RAYGUI_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build raygui examples

add_subdirectory(raylib raylib/bin)
add_subdirectory(raygui/projects/CMake)
add_subdirectory(rdrawing)

