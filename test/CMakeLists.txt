add_executable(tuples_test_app tuples_test.c)
target_link_libraries(tuples_test_app lib unity m)
add_test(tuples_test tuples_test_app)


add_executable(canvas_test_app canvas_test.c)
target_link_libraries(canvas_test_app lib unity m)
add_test(canvas_test canvas_test_app)

add_executable(matrices_test_app matrices_test.c)
target_link_libraries(matrices_test_app lib unity m)
add_test(matrices_test matrices_test_app)


add_executable(transformations_test_app transformations_test.c)
target_link_libraries(transformations_test_app lib unity m)
add_test(transformations_test transformations_test_app)

add_executable(rays_test_app rays_test.c)
target_link_libraries(rays_test_app lib unity m)
add_test(rays_test rays_test_app)

add_executable(sphere_test_app sphere_test.c)
target_link_libraries(sphere_test_app lib unity m)
add_test(sphere_test sphere_test_app)