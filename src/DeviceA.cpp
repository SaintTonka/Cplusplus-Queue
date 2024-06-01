
#ifndef DEVICEA_H
#define DEVICEA_H

#include "Device.h"
#include <thread>
#include <chrono>
#include <cstdlib>

class DeviceA : public Device {
public:
    std::string getName() override;
    std::string getDataAsString() override;
};

#endif // DEVICEA_H