#include "Parser.h"
#include <iostream>
#include <thread>
#include "WorkDoneEvent.h"
#include "DataEvent.h"
#include "StartedEvent.h"

using namespace std;

Parser::Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> A, std::shared_ptr<Device> B)
  : queue(queue), A(A), B(B) {}

void Parser::run(size_t loop_count_A, size_t loop_count_B, int crush_index_A, int crush_index_B) {
  std::thread threadA(&Parser::read, this, A, std::chrono::seconds(1), loop_count_A, crush_index_A);
  std::thread threadB(&Parser::read, this, B, std::chrono::seconds(5), loop_count_B, crush_index_B);


  while (true) {
    auto event = queue->pop(std::chrono::seconds(5));
    if (event == nullptr) {
      std::cout << "No events received for 5 seconds. Exiting..." << std::endl;
      break;
    }
    if (auto startedEvent = std::static_pointer_cast<const StartedEvent>(event)) {
      std::cout << startedEvent->toString() << std::endl;
    }
    if (auto dataEvent = std::static_pointer_cast<const DataEvent>(event)) {
      std::cout << dataEvent->toString() << std::endl;
    }
    if (auto workDoneEvent = std::static_pointer_cast<const WorkDoneEvent>(event)) {
      std::cout << workDoneEvent->toString() << std::endl;
      if (workDoneEvent->getDevice()->getName() == "DeviceA" && loop_count_A > 0) {
        loop_count_A--;
      } else if (workDoneEvent->getDevice()->getName() == "DeviceB" && loop_count_B > 0) {
        loop_count_B--;
      }
      if (loop_count_A == 0 && loop_count_B == 0) {
        cout << "All data received. Exiting..." << endl;
        break;
      }
    }
  }

  threadA.join();
  threadB.join();
}

void Parser::read(std::shared_ptr<Device> device, std::chrono::seconds sleep_duration, size_t loop_count, int crush_index) {
    queue->push(std::make_shared<StartedEvent>(device));

    for (size_t i = 0; i < loop_count; ++i) {
        if (static_cast<int>(i) == crush_index) {
            cout << "Device " << device->getName() << " has stopped responding." << endl; 
            continue;
        }
        std::this_thread::sleep_for(sleep_duration);
        string data = device->getDataAsString();
        queue->push(std::make_shared<DataEvent>(device, data));
    }
    queue->push(std::make_shared<WorkDoneEvent>(device));
}