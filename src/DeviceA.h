#ifndef DEVICEA_H
#define DEVICEA_H
#include <string>
#include "Device.h"

class DeviceA : public Device {
public:
    std::string getName() const override;
    std::string getDataAsString() override;
};


std::string generateRandomDataDeviceA(size_t length);
#endif
