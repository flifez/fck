cmake_minimum_required(VERSION 3.30)
project(fck)

set(CMAKE_CXX_STANDARD 20)

add_library(fck.Core "")
add_subdirectory(src)

add_executable(fck src/main.cpp
        src/main.h)
target_link_libraries(fck fck.Core)
