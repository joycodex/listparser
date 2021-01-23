cmake_minimum_required(VERSION 3.5)

project(listparser LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core)

add_executable(listparser
    main.cpp)

target_link_libraries(listparser lexer)
