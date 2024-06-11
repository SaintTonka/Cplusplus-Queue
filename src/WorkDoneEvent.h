#ifndef WORKDONEEVENT_H
#define WORKDONEEVENT_H

#include "DeviceEvent.h"

class WorkDoneEvent : public DeviceEvent {
public:
    WorkDoneEvent(const std::shared_ptr<const Device>& device); 
    std::string toString() const override;
};

#endif 