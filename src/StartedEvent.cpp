#include "StartedEvent.h"

StartedEvent::StartedEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {}  // Исправлено

std::string StartedEvent::toString() const {
    return "StartedEvent: Device: " + getDevice()->getName();
}