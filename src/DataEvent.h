#ifndef DATAEVENT_H
#define DATAEVENT_H

#include "DeviceEvent.h"
#include <string>

class DataEvent : public DeviceEvent {
public:
    DataEvent(const std::shared_ptr<const Device>& device);
    DataEvent(const std::shared_ptr<const Device>& device, const std::string& data);
    std::string toString() const override;
private:
    std::string data;
};

#endif