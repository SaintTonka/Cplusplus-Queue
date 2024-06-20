#include "DeviceA.h"
#include <thread>
#include <chrono>
#include <cstdlib>

std::string DeviceA::getName() const {
    return "DeviceA";
}

std::string DeviceA::getDataAsString() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return std::string(rand() % 501, 'A'); 
}