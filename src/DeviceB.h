#ifndef DEVICEB_H
#define DEVICEB_H

#include "Device.h"
#include <thread>
#include <chrono>
#include <sstream>

class DeviceB : public Device {
public:
    std::string getName() const override {  // Marked as const
        return "DeviceB";
    }

    std::string getDataAsString() override {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::stringstream ss;
        ss << rand() % 199 << "," << rand() % 199 << "," << rand() % 199;
        return ss.str();
    }
};

#endif // DEVICEB_H
