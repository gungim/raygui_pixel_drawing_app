set(rdrawing_public_headers
    rdrawing.h utils.h
    )

set(rdrawing_sources
    rdrawing.c utils.c
    )

add_library(rdrawing ${rdrawing_sources} ${rdrawing_public_headers})

target_link_libraries(rdrawing
	raylib)
