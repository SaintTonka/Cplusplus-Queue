#ifndef STARTEDEVENT_H
#define STARTEDEVENT_H

#include "DeviceEvent.h"

class StartedEvent : public DeviceEvent {
public:
    StartedEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {}

    std::string toString() const override {
        return "StartedEvent from " + getDevice()->getName();
    }
};

#endif // STARTEDEVENT_H