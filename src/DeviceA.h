#ifndef DEVICEA_H
#define DEVICEA_H

#include "Device.h"
#include <thread>
#include <chrono>
#include <cstdlib>

class DeviceA : public Device {
public:
    std::string getName() const override {  // Marked as const
        return "DeviceA";
    }

    std::string getDataAsString() override {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return std::string(rand() % 501, 'A');
    }
};

#endif // DEVICEA_H
