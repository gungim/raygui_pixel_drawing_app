
set(SOURCES
	# test2.cpp
	# test1.cpp
	# test3.cpp

	main.cpp
	new_win.cpp
	draw_win.cpp
	app_utils.cpp
	topbar.cpp
	import_file.cpp
	context.cpp
)

set(HEADERS
	new_win.hpp
	draw_win.hpp
	app_utils.hpp
	topbar.hpp
	context.hpp
	import_file.hpp
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} raylib raygui)
