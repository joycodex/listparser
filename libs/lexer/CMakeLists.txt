cmake_minimum_required(VERSION 3.5)

project(lexer LANGUAGES CXX)

add_library(${PROJECT_NAME}
    include/lexer/char_stream.h
    include/lexer/list_lexer.h
    include/lexer/token.h
    src/char_stream.cpp
    src/list_lexer.cpp
    src/token.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include)

target_link_libraries(${PROJECT_NAME})

add_subdirectory(tests)
