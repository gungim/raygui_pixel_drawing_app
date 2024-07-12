
set(SOURCES
	# test2.cpp
	# test1.cpp
	# test3.cpp

	main.cpp

	app.cpp
	app_utils.cpp
	context.cpp
	draw_win.cpp
	import_file.cpp
	main_window.cpp
	new_win.cpp
	toolbar.cpp
	topbar.cpp
	workspace.cpp
	workspaces.cpp
	workspaces_pannel.cpp
	template.cpp
)

set(HEADERS
	app.hpp
	app_utils.hpp
	context.hpp
	draw_win.hpp
	import_file.hpp
	main_window.hpp
	new_win.hpp
	toolbar.hpp
	topbar.hpp
	workspace.hpp
	workspaces.hpp
	workspaces_pannel.hpp
	template.hpp
)


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib raygui)
