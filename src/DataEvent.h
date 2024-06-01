#ifndef DATAEVENT_H
#define DATAEVENT_H

#include "DeviceEvent.h"

class DataEvent : public DeviceEvent
{
public:
    DataEvent(const std::shared_ptr<const Device>& device); // Corrected constructor
    DataEvent(const std::shared_ptr<const Device>& device, const std::string& data); 
    std::string toString() const override;
private:
    std::string data;
};


#endif 