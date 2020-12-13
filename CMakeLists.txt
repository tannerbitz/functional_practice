cmake_minimum_required(VERSION 3.1)

project(FunctionalPractice VERSION 1.0
                           DESCRIPTION "Practicing some functional style C++"
                           LANGUAGES CXX)

SET(TARGET_NAME "fp")
add_executable(${TARGET_NAME} src/main.cpp
                              src/FileLength.cpp
                              include/FileLength.h)

# Conan imports
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

target_include_directories(${TARGET_NAME} PRIVATE include)
target_link_libraries(${TARGET_NAME} PRIVATE CONAN_PKG::range-v3)
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
target_compile_options(${TARGET_NAME} PRIVATE ${opts})
