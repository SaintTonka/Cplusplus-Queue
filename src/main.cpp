#include "Device.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include "EventQueue.h"
#include "Parser.h"
#include <memory>
#include <iostream>
#include <cstdlib>

int main() {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    Parser parser;

    parser.run();
    parser.process(deviceA);
    parser.process(deviceB);

    return 0;
}
