#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <iostream>
#include "Device.h"

class Parser {
public:
    Parser() = default;

    void process(std::shared_ptr<Device> device) {
        std::cout << "StartedEvent: Device: " << device->getName() << std::endl;
        std::string data = device->getDataAsString();
        std::cout << "DataEvent: Device: " << device->getName() << ", Data: " << data << std::endl;
        std::cout << "WorkDoneEvent: Device: " << device->getName() << std::endl;
    }

    void run() {
        std::cout << "Parser is running" << std::endl;
    }
};

#endif 
