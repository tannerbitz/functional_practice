cmake_minimum_required(VERSION 3.1)

project(FunctionalPractice VERSION 1.0
                           DESCRIPTION "Practicing some functional style C++"
                           LANGUAGES CXX)

SET(TARGET_NAME "fp")
add_executable(${TARGET_NAME} src/main.cpp
                              src/FileLength.cpp
                              include/FileLength.h)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

find_package(range-v3 0.10.0 EXACT REQUIRED)

target_include_directories(${TARGET_NAME} PUBLIC include)
target_link_libraries(${TARGET_NAME} PUBLIC range-v3::range-v3)
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
