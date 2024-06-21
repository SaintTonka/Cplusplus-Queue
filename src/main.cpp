#include "Device.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include "EventQueue.h"
#include "Parser.h"
#include <memory>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <loop_count_A> <loop_count_B> [crush_index_A] [crush_index_B]" << std::endl;
        return 1;
    }
    size_t loop_count_A = std::stoul(argv[1]);
    size_t loop_count_B = std::stoul(argv[2]);
    int crush_index_A = -1;
    int crush_index_B = -1;

    if (argc >= 4) {
        crush_index_A = std::stoi(argv[3]);
    }

    if (argc >= 5) {
        crush_index_B = std::stoi(argv[4]);
    }

    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    auto deviceB = std::make_shared<DeviceB>();
    auto eventQueue = std::make_shared<EventQueue>();
    Parser parser(eventQueue, deviceA, deviceB);
    parser.run(loop_count_A, loop_count_B, crush_index_A, crush_index_B); 
    return 0;
}
