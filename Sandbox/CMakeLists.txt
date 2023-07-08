project(Sandbox)

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main PRIVATE Lucent)

# Copy Resource folder after every build
 add_custom_command(
        TARGET main
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/res
                ${CMAKE_CURRENT_BINARY_DIR}/res
 )
