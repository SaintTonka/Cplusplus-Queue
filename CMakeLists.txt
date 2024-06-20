cmake_minimum_required(VERSION 3.15.0)

project(parallel_executor VERSION 1.0.0 DESCRIPTION "Синхронизация нескольких потоков исполнения через очередь сообщений на C++")

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)

add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(test)

enable_testing()
