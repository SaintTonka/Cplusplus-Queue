include(${GTest_SOURCE_DIR}/cmake/gtest.cmake)

# Set the build type
set(CMAKE_BUILD_TYPE Debug)

# Add the test files
add_subdirectory(test)

# Build the test executables
add_executable(Test_Devices ${CMAKE_CURRENT_SOURCE_DIR}/Test_Devices.cpp)
add_executable(Test_EventQueue ${CMAKE_CURRENT_SOURCE_DIR}/Test_EventQueue.cpp)
add_executable(Test_Events ${CMAKE_CURRENT_SOURCE_DIR}/Test_Events.cpp)
add_executable(Test_Parser ${CMAKE_CURRENT_SOURCE_DIR}/Test_Parser.cpp)

# Link the test executables with the Google Test library
target_link_libraries(Test_Devices gtest gtest_main)
target_link_libraries(Test_EventQueue gtest gtest_main)
target_link_libraries(Test_Events gtest gtest_main)
target_link_libraries(Test_Parser gtest gtest_main)

# Specify the test targets
add_test(NAME Test_Devices COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Devices)
add_test(NAME Test_EventQueue COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_EventQueue)
add_test(NAME Test_Events COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Events)
add_test(NAME Test_Parser COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Parser)

# Include the source code of your project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
