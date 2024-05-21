# test/CMakeLists.txt

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src) 

add_executable(test_parallel_executor test_main.cpp)
target_link_libraries(test_parallel_executor gtest)

add_test(NAME parallel_executor_tests COMMAND test_parallel_executor)
set(CMAKE_BUILD_TYPE Release) 