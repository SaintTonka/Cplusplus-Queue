#include "Parser.h"
#include "StartedEvent.h"
#include "DataEvent.h"
#include "WorkDoneEvent.h"
#include <iostream>
#include <thread>
#include <memory>


Parser::Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> A, std::shared_ptr<Device> B)
    : queue(queue), A(A), B(B) {}

void Parser::run(size_t loop_count_A, size_t loop_count_B, int crush_index_A, int crush_index_B) {
  std::thread threadA(&Parser::read, this, A, std::chrono::seconds(1), loop_count_A, crush_index_A);
  std::thread threadB(&Parser::read, this, B, std::chrono::seconds(5), loop_count_B, crush_index_B);

  bool deviceA_done = false;
  bool deviceB_done = false;

  while (true) {
    auto event = queue->pop(std::chrono::seconds(5));
    if (event == nullptr) {
      std::cout << "No events received for 5 seconds. Exiting..." << std::endl;
      break;
    }
    if (auto startedEvent = std::dynamic_pointer_cast<const StartedEvent>(event)) {
      std::cout << startedEvent->toString() << std::endl;
    } else if (auto dataEvent = std::dynamic_pointer_cast<const DataEvent>(event)) {
      std::cout << dataEvent->toString() << std::endl;
    } else if (auto workDoneEvent = std::dynamic_pointer_cast<const WorkDoneEvent>(event)) {
      std::cout << workDoneEvent->toString() << std::endl;
      if (workDoneEvent->getDevice()->getName() == "DeviceA") {
        deviceA_done = true;
      } else if (workDoneEvent->getDevice()->getName() == "DeviceB") {
        deviceB_done = true;
      }
      if (deviceA_done && deviceB_done) {
        std::cout << "All devices done. Exiting..." << std::endl;
        break;
      }
    } else {
      std::cout << "Unknown event type received." << std::endl;
    }
  }

  threadA.join();
  threadB.join();
  std::cout << "Both threads have been joined." << std::endl;
}

void Parser::read(std::shared_ptr<Device> device, std::chrono::seconds sleep_duration, size_t loop_count, int crush_index) {
    queue->push(std::make_shared<StartedEvent>(device));

    for (size_t i = 0; i < loop_count; ++i) {
        if (static_cast<int>(i) == crush_index) {
            std::cout << "Device " << device->getName() << " has stopped responding." << std::endl; 
            continue;
        }
        std::this_thread::sleep_for(sleep_duration);
        std::string data = device->getDataAsString();
        queue->push(std::make_shared<DataEvent>(device, data));
    }
    queue->push(std::make_shared<WorkDoneEvent>(device));
}
