cmake_minimum_required(VERSION 3.0.0)

project(list_parser_test VERSION 0.1 LANGUAGES CXX)

enable_testing()

add_executable(${PROJECT_NAME}
    list_parser_test.cpp)

target_link_libraries(${PROJECT_NAME} gtest_main parser)
