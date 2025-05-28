cmake_minimum_required(VERSION 3.14)
project(PizzaPatterns)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_subdirectory(tests)
add_subdirectory(examples)
