#include "StartedEvent.h"

StartedEvent::StartedEvent(std::shared_ptr<Device> device) : DeviceEvent(device) {}

std::string StartedEvent::toString() const {
  return "StartedEvent: Device: " + getDevice()->getName();
}