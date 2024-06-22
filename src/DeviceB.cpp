#include "DeviceB.h"
#include <thread>
#include <chrono>
#include <sstream>
#include <cstdlib>

std::string DeviceB::getName() const {
    return "DeviceB";
}

std::string DeviceB::getDataAsString() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int a = rand() % 199;
    int b = rand() % 199;
    int c = rand() % 199;
    std::ostringstream oss;
    oss << a << " " << b << " " << c;
    return oss.str();
}
