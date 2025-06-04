cmake_minimum_required(VERSION 3.14)
project(PizzaPatterns)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Para proyectos que usan CMake >=3.14
FetchContent_MakeAvailable(googletest)

add_subdirectory(tests)
add_subdirectory(examples)
