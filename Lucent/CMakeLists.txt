project(Lucent)




file(GLOB_RECURSE LUCENT_ALL_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_library(Lucent STATIC)

target_sources(Lucent PRIVATE ${LUCENT_ALL_SOURCES})
target_include_directories(Lucent PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_compile_features(Lucent PUBLIC cxx_std_17)


find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
# find_package(stb CONFIG REQUIRED) 
find_package(box2d CONFIG REQUIRED)

target_link_libraries(Lucent PUBLIC glfw)
target_link_libraries(Lucent PUBLIC glm::glm)
target_link_libraries(Lucent PUBLIC glad::glad)
target_link_libraries(Lucent PUBLIC box2d::box2d)

