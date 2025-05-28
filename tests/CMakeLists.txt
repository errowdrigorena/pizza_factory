include(CTest)
enable_testing()

# Activar flags para cobertura
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(--coverage -O0)
    link_libraries(--coverage)
endif()

add_executable(test_runner
    test_factory_method.cpp
    test_abstract_factory.cpp
)
target_link_libraries(test_runner
    gtest
    gtest_main
    pthread
)

target_include_directories(test_runner PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ingredients
    ${CMAKE_SOURCE_DIR}/include/factory
    ${CMAKE_SOURCE_DIR}/examples/factory_method
    ${CMAKE_SOURCE_DIR}/examples/abstract_factory
)

include(GoogleTest)
gtest_discover_tests(test_runner)
