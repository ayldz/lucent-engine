project(Sandbox)

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(main PRIVATE Lucent)

