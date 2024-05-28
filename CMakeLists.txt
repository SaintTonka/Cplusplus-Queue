cmake_minimum_required(VERSION 3.10)

project(my_project)

# Set build type
set(CMAKE_BUILD_TYPE Debug)



# Set the paths to Google Test libraries and headers 
set(GTEST_LIBRARY_DIR "C:\\Users\\danii\\Desktop\\gtest\\lib") 
set(GTEST_INCLUDE_DIR "C:\\Users\\danii\\Desktop\\gtest\\include")

find_package(GTest REQUIRED)

# Add source files
add_subdirectory(src) 

# Add test files
add_subdirectory(test) 

# Specify test executables 
add_executable(Test_Devices ${CMAKE_CURRENT_SOURCE_DIR}/test/Test_Devices.cpp)
add_executable(Test_EventQueue ${CMAKE_CURRENT_SOURCE_DIR}/test/Test_EventQueue.cpp)
add_executable(Test_Events ${CMAKE_CURRENT_SOURCE_DIR}/test/Test_Events.cpp)
add_executable(Test_Parser ${CMAKE_CURRENT_SOURCE_DIR}/test/Test_Parser.cpp)

# Link test executables with Google Test
target_link_libraries(Test_Devices gtest gtest_main)
target_link_libraries(Test_EventQueue gtest gtest_main)
target_link_libraries(Test_Events gtest gtest_main)
target_link_libraries(Test_Parser gtest gtest_main)

# Specify test targets 
add_test(NAME Test_Devices COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Devices)
add_test(NAME Test_EventQueue COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_EventQueue)
add_test(NAME Test_Events COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Events)
add_test(NAME Test_Parser COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Parser)