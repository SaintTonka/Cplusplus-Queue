#include "DeviceA.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
std::string generateRandomDataDeviceA(size_t length) {
    static const std::string alphanum =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        result += alphanum[rand() % alphanum.size()];
    }

    return result;
}

std::string DeviceA::getName() const {
    return "DeviceA";
}

std::string DeviceA::getDataAsString() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    size_t length = 10 + rand() % 41; 
    return generateRandomDataDeviceA(length);
}