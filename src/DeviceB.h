#ifndef DEVICEB_H
#define DEVICEB_H

#include "Device.h"
#include <string>

class DeviceB : public Device {
public:
    std::string getName() const override;
    std::string getDataAsString() override;
};

#endif 
