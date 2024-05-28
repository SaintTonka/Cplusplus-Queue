#ifndef WORKDONEEVENT_H
#define WORKDONEEVENT_H

#include "DeviceEvent.h"

class WorkDoneEvent : public DeviceEvent {
public:
    WorkDoneEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {}

    std::string toString() const override {
        return "WorkDoneEvent from " + getDevice()->getName();
    }
};

#endif // WORKDONEEVENT_H

