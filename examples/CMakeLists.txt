add_executable(factory_method_main factory_method/main.cpp)
target_include_directories(factory_method_main PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/factory_method)

add_executable(abstract_factory_main abstract_factory/main.cpp)
target_include_directories(abstract_factory_main PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/abstract_factory)
