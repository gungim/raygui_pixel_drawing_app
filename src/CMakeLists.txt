
set(SOURCES
	# test2.cpp
	# test1.cpp
	# test3.cpp

	main.cpp

	app.cpp
	app_utils.cpp
	context.cpp
	import_file.cpp
	main_window.cpp
	toolbar.cpp
	topbar.cpp
	workspace.cpp
	workspaces.cpp
	workspaces_pannel.cpp
	template.cpp
	win/new_win.cpp
	win/resize_canvas.cpp
)

set(HEADERS
	app.hpp
	app_utils.hpp
	context.hpp
	import_file.hpp
	main_window.hpp
	toolbar.hpp
	topbar.hpp
	workspace.hpp
	workspaces.hpp
	workspaces_pannel.hpp
	template.hpp
	win/new_win.hpp
	win/resize_canvas.hpp
)

add_subdirectory(ui)
add_subdirectory(libs/rdrawing)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ui-lib rdrawing)
