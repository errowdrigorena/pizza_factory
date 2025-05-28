add_executable(factory_method_example
    main.cpp
)

target_include_directories(factory_method_example PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/examples/factory_method
    ${CMAKE_SOURCE_DIR}/examples/factory_method/ingredient_creators
) 