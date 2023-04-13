


add_library(lib STATIC
    tuples.c
    canvas.c
    matrices.c
    transformations.c
    rays.c
)

target_include_directories(lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(lib PRIVATE m)