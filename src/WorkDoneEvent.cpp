#include "WorkDoneEvent.h"

WorkDoneEvent::WorkDoneEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {} 

std::string WorkDoneEvent::toString() const {
    return "WorkDoneEvent: Device: " + getDevice()->getName(); 
}