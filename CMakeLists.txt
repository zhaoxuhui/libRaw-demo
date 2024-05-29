cmake_minimum_required(VERSION 3.2)
project(libRaw_demo)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(libRaw_demo main.cpp)
target_link_libraries(libRaw_demo
        ${OpenCV_LIBS}
        /usr/local/lib/libraw.so
        )