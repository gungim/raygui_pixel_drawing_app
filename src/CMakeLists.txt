
set(SOURCES
  main.cpp
	new_project.cpp
)

set(HEADERS
	new_project.h
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} raylib raygui)
