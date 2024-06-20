#include "DeviceB.h"
#include <thread>
#include <chrono>
#include <cstdlib>

std::string DeviceB::getName() const {
    return "DeviceB_Mock";
}

std::string DeviceB::getDataAsString() {
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return std::string("DeviceB_Mock_Data");
}