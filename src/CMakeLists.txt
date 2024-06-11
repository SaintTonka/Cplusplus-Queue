cmake_minimum_required(VERSION 3.10)

add_library(my_project SHARED 
    Device.cpp
    DeviceA.cpp
    DeviceB.cpp
    EventQueue.cpp
    StartedEvent.cpp
    DeviceEvent.cpp  
    DataEvent.cpp
    WorkDoneEvent.cpp
    Parser.cpp
)

target_include_directories(my_project PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
