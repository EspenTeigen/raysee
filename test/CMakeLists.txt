add_executable(ray_app
                tuples_test.c)

target_link_libraries(ray_app
                        lib
                        unity)

add_test(ray_test ray_app)