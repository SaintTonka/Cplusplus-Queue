cmake_minimum_required(VERSION 3.10)
project(my_project_test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/include)

set(TEST_SOURCES
    Test_Devices.cpp
    Test_EventQueue.cpp
    Test_Events.cpp
    Test_Parser.cpp
)

enable_testing()

foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} gtest gtest_main my_project)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

