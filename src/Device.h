#ifndef DEVICE_H
#define DEVICE_H

#include <string>
class Device {
public:
    virtual ~Device() = default;
    virtual std::string getName() const = 0;
    virtual std::string getDataAsString() = 0;
};
#endif