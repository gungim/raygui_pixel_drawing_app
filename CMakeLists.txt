cmake_minimum_required(VERSION 3.5)

project(pixel_drawing_app CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_RAYGUI_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build raygui examples

add_subdirectory(libs)

add_subdirectory(src)
