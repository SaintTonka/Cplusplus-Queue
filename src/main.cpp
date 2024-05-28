#include "EventQueue.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include "Parser.h"
#include <iostream>

int main() {
    auto queue = std::make_shared<EventQueue>();
    auto deviceA = std::make_shared<DeviceA>();
    auto deviceB = std::make_shared<DeviceB>();

    Parser parser(queue, deviceA, deviceB);
    parser.run(10, 10);

    while (true) {
        auto event = queue->pop(std::chrono::seconds(5));
        if (!event) {
            std::cout << "No events received for 5 seconds, exiting." << std::endl;
            break;
        }
        std::cout << event->toString() << std::endl;
    }

    return 0;
}
