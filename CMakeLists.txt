cmake_minimum_required(VERSION 3.5)

project(test_stl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
        stl_mass.h
        stl_mass.cpp
)

add_executable(test_stl
    ${PROJECT_SOURCES}
)

install(TARGETS test_stl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
