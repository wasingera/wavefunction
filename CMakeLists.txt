cmake_minimum_required(VERSION 3.23)

project(Wave)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

set(SRC_FILES src/main.cpp src/Rules.cpp src/utility.cpp)

add_executable(wave ${SRC_FILES})
target_include_directories(wave PUBLIC include)
