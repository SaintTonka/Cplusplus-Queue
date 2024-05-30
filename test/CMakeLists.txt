include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(Test_Devices ${CMAKE_CURRENT_SOURCE_DIR}/Test_Devices.cpp)
add_executable(Test_EventQueue ${CMAKE_CURRENT_SOURCE_DIR}/Test_EventQueue.cpp)
add_executable(Test_Events ${CMAKE_CURRENT_SOURCE_DIR}/Test_Events.cpp)
add_executable(Test_Parser ${CMAKE_CURRENT_SOURCE_DIR}/Test_Parser.cpp)

# target_link_libraries(multiply_test
#  PRIVATE
#   GTest::GTest
#   multiply)

target_link_libraries(Test_Devices gtest gtest_main)
target_link_libraries(Test_EventQueue gtest gtest_main)
target_link_libraries(Test_Events gtest gtest_main)
target_link_libraries(Test_Parser gtest gtest_main)



add_test(NAME Test_Devices COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Devices)
add_test(NAME Test_EventQueue COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_EventQueue)
add_test(NAME Test_Events COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Events)
add_test(NAME Test_Parser COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Test_Parser)