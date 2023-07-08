cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "VCPKG toolchain file")
set(VCPKG_MANIFEST_MODE TRUE CACHE BOOL "VCPKG activate manifest mode")

project(LucentEngine)


add_subdirectory(Lucent)
add_subdirectory(Sandbox)
