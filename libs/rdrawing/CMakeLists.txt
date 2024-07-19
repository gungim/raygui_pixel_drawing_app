project(rdrawing C)
set(PROJECT_VERSION 1.0.0)
set(API_VERSION 100)

find_package(raylib REQUIRED)

set(rdrawing_public_headers
    src/rdrawing.h
    )

set(rdrawing_sources
    src/rdrawing.c src/utils.c
    )

add_library(rdrawing ${rdrawing_sources} ${rdrawing_public_headers})

set_target_properties(rdrawing PROPERTIES
                      PUBLIC_HEADER "${rdrawing_public_headers}"
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${API_VERSION}
                      )
target_link_libraries(rdrawing PRIVATE raylib)

target_include_directories(rdrawing PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
target_include_directories(rdrawing PUBLIC src)
