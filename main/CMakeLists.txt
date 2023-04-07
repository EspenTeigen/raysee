add_executable(main
    main.c
    projectile_path/projectile_path.c
    create_canvas/create_canvas.c
    analog_clock/analog_clock.c
)


target_link_libraries(main
    lib
)