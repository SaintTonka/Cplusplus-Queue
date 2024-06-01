cmake_minimum_required(VERSION 3.15)
project(my_project_test)

# 1. Загружаем Google Test с помощью FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# 2. Добавляем директории для заголовочных файлов
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src) #  Добавляем директорию src
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..) #  Добавляем корневую директорию

# 3. Создаем исполняемые файлы тестов
add_executable(Test_Devices ${CMAKE_CURRENT_SOURCE_DIR}/Test_Devices.cpp)
add_executable(Test_EventQueue ${CMAKE_CURRENT_SOURCE_DIR}/Test_EventQueue.cpp)
add_executable(Test_Events ${CMAKE_CURRENT_SOURCE_DIR}/Test_Events.cpp)
add_executable(Test_Parser ${CMAKE_CURRENT_SOURCE_DIR}/Test_Parser.cpp)

# 4. Подключаем библиотеки к тестовым исполняемым файлам
target_link_libraries(Test_Devices gtest my_project)
target_link_libraries(Test_EventQueue gtest my_project)
target_link_libraries(Test_Events gtest my_project)
target_link_libraries(Test_Parser gtest my_project)

# 5. Добавляем тесты
add_test(NAME Test_Devices COMMAND Test_Devices)
add_test(NAME Test_EventQueue COMMAND Test_EventQueue)
add_test(NAME Test_Events COMMAND Test_Events)
add_test(NAME Test_Parser COMMAND Test_Parser)