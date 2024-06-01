#ifndef DEVICE_EVENT_H
#define DEVICE_EVENT_H

#include <iostream>
#include <memory>
#include "Event.h"
#include "Device.h"

class DeviceEvent : public Event {
public:
    DeviceEvent(const std::shared_ptr<const Device>& device) : device(device) {} // Исправлен конструктор
    std::shared_ptr<const Device> getDevice() const { return device; }

private:
    std::shared_ptr<const Device> device;
};

#endif