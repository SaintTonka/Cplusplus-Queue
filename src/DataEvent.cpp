#include "DataEvent.h"
#include <string> 

DataEvent::DataEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {} 

DataEvent::DataEvent(const std::shared_ptr<const Device>& device, const std::string& data)
    : DeviceEvent(device),  
      data(data) {} 

std::string DataEvent::toString() const {
    return "DataEvent: Device: " + getDevice()->getName() + ", Data: " + data; 
}