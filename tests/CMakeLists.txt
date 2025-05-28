include(CTest)
enable_testing()

# Incluir GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Activar flags para cobertura
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(--coverage -O0)
    link_libraries(--coverage)
endif()

add_executable(pizza_tests
    test_abstract_factory.cpp
    test_factory_method.cpp
)

target_include_directories(pizza_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/examples/factory_method
    ${CMAKE_SOURCE_DIR}/examples/factory_method/ingredient_creators
    ${CMAKE_SOURCE_DIR}/examples/abstract_factory
    ${CMAKE_SOURCE_DIR}/examples/abstract_factory/ingredient_creators
)

target_link_libraries(pizza_tests PRIVATE
    GTest::gtest_main
    GTest::gmock_main
)

gtest_discover_tests(pizza_tests)

# Agregar un bloque (por ejemplo, con FetchContent) para descargar (y configurar) lcov desde CMake, de modo que se instale (o se configure) automáticamente (por ejemplo, en el directorio de build) y se pueda usar (por ejemplo, para generar el informe de cobertura) sin necesidad de instalarlo manualmente (por ejemplo, con apt).
# (Se requiere que el módulo FetchContent esté incluido, por ejemplo, con include(FetchContent) en el CMakeLists.txt raíz.)
include(FetchContent)
FetchContent_Declare(lcov
  GIT_REPOSITORY https://github.com/linux-test-project/lcov.git
  GIT_TAG v1.16
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)
FetchContent_MakeAvailable(lcov)
# (Opcional: agregar un target (por ejemplo, coverage) que ejecute (por ejemplo, con add_custom_target) lcov (por ejemplo, con COMMAND lcov --directory . --capture --output-file coverage.info && lcov --remove coverage.info '/usr/*' '*/_deps/*' --output-file coverage.info && genhtml coverage.info --output-directory coverage_report) para generar el informe de cobertura.)
 add_custom_target(coverage
 COMMAND lcov --directory . --capture --output-file coverage.info --ignore-errors mismatch
 COMMAND lcov --remove coverage.info '/usr/*' '*/_deps/*' --output-file coverage.info
 COMMAND genhtml coverage.info --output-directory coverage_report --ignore-errors mismatch
 DEPENDS pizza_tests
 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
 COMMENT "Generando informe de cobertura (lcov) ..."
 )
