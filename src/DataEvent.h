#ifndef DATAEVENT_H
#define DATAEVENT_H

#include "DeviceEvent.h"
#include <string>
#include <memory>

class DataEvent : public DeviceEvent {
public:
    DataEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {}  // Constructor taking shared_ptr<const Device>
    DataEvent(const std::shared_ptr<const Device>& device, const std::string& data) : DeviceEvent(device), data(data) {}

    std::string toString() const override {
        return "DataEvent from " + getDevice()->getName() + ": " + data;
    }

private:
    std::string data;
};

#endif // DATAEVENT_H
