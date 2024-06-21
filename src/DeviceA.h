#ifndef DEVICEA_H
#define DEVICEA_H

#include "Device.h"
#include <string>

class DeviceA : public Device {
public:
    std::string getName() const override;  
    std::string getDataAsString() override;
};

#endif
