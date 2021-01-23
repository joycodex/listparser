cmake_minimum_required(VERSION 3.5)

project(parser LANGUAGES CXX)

add_library(${PROJECT_NAME}
    include/parser/list_parser.h
    src/list_parser.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include)

target_link_libraries(${PROJECT_NAME} lexer)

add_subdirectory(tests)
