
add_library(lib STATIC
    tuples.c
)

target_include_directories(lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(lib PRIVATE m)