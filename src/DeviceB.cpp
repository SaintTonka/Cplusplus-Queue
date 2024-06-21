#include "DeviceB.h"
#include <thread>
#include <chrono>
#include <cstdlib>

std::string DeviceB::getName() const {
    return "DeviceB";
}

std::string DeviceB::getDataAsString() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    int a = rand() % 199;
    int b = rand() % 199;
    int c = rand() % 199;
    return std::to_string(a) + " " + std::to_string(b) + " " + std::to_string(c);
}
