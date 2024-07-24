add_library(ui-lib
	win_widget.cpp
	new_win.cpp
	new_win.hpp
	resize_canvas.cpp
	resize_canvas.hpp

)
target_link_libraries(ui-lib
	raylib
	raygui
)
