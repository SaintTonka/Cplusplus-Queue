#ifndef DEVICE_EVENT_H
#define DEVICE_EVENT_H

#include "Event.h"
#include "Device.h"
#include <memory>

class DeviceEvent : public Event {
public:
    DeviceEvent(const std::shared_ptr<const Device>& device); 
    std::shared_ptr<const Device> getDevice() const { return device; }

private:
    std::shared_ptr<const Device> device; 
};

#endif