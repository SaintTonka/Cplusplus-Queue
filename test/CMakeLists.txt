cmake_minimum_required(VERSION 3.10)
project(my_project_test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/include)


link_directories(${CMAKE_CURRENT_BINARY_DIR}/../googletest/googletest)


set(TEST_SOURCES
    DeviceATest.cpp
    DeviceBTest.cpp
    EventQueueTest.cpp
    EventsTest.cpp
    ParserTest.cpp
)


foreach(test_source IN LISTS TEST_SOURCES)  
    add_executable(${test_source} ${CMAKE_CURRENT_SOURCE_DIR}/${test})  
    target_link_libraries(${test_source} gtest gtest_main my_project) 
    add_test(NAME ${test_source} COMMAND ${test_source}) 
endforeach()
