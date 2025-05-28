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
 COMMAND lcov --directory . --capture --output-file coverage.info
 COMMAND lcov --remove coverage.info '/usr/*' '*/_deps/*' --output-file coverage.info
 COMMAND genhtml coverage.info --output-directory coverage_report
 DEPENDS test_runner
 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
 COMMENT "Generando informe de cobertura (lcov) ..."
 )
