cmake_minimum_required(VERSION 3.10)


add_library(my_project INTERFACE) 


target_include_directories(my_project INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)