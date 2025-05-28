
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

add_test(NAME all_tests COMMAND test_runner)
