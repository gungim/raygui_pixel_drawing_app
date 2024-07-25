include_directories(.)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(app)
target_link_libraries(${PROJECT_NAME} app-lib)


# add_executable(${PROJECT_NAME} main_test.cpp)
