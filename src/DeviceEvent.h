#ifndef DEVICEEVENT_H
#define DEVICEEVENT_H

#include "Event.h"
#include "Device.h"
#include <memory>

class DeviceEvent : public Event {
public:
    DeviceEvent(const std::shared_ptr<const Device>& device) : device(device) {}
    std::shared_ptr<const Device> getDevice() const { return device; }

private:
    std::shared_ptr<const Device> device;
};

#endif // DEVICEEVENT_H
