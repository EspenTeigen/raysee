project(raytracer)
cmake_minimum_required(VERSION 3.24)
set(CMAKE_C_STANDARD 17)

set(TARGET_GROUP production CACHE STRING "Group to build")


add_subdirectory(lib)

if(TARGET_GROUP STREQUAL prod)
    add_subdirectory(main)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -03")
elseif(TARGET_GROUP STREQUAL test)
    include(CTest)
    add_subdirectory(external)
    add_subdirectory(test)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -wall")
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()