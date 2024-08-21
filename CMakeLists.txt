cmake_minimum_required(VERSION 3.5.0)
project(MemoryLeak VERSION 0.1.0 LANGUAGES CXX)

set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)


add_executable(Allocate ${SRC_DIR}/AllocateMemory.cpp)
add_executable(Leak ${SRC_DIR}/LeakMemory.cpp)

