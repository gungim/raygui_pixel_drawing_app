add_library(ui-lib
	win_widget.cpp
)

target_link_libraries(ui-lib
	raylib
	raygui)
