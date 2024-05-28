#ifndef PARSER_H
#define PARSER_H

#include "EventQueue.h"
#include "Device.h"
#include "WorkDoneEvent.h"
#include "DataEvent.h"
#include <thread>
#include <chrono>

class Parser {
public:
    Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> A, std::shared_ptr<Device> B)
        : queue(queue), A(A), B(B) {}

    void run(size_t loop_count_A, size_t loop_count_B, int crush_index_A = -1, int crush_index_B = -1) {
        std::thread threadA(&Parser::read, this, A, std::chrono::seconds(1), loop_count_A, crush_index_A);
        std::thread threadB(&Parser::read, this, B, std::chrono::seconds(5), loop_count_B, crush_index_B);
        threadA.join();
        threadB.join();
    }

private:
    void read(std::shared_ptr<Device> device, std::chrono::seconds sleep_duration, size_t loop_count, int crush_index) {
        for (size_t i = 0; i < loop_count; ++i) {
            if (i == crush_index) {
                break;
            }
            std::string data = device->getDataAsString();
            queue->push(std::make_shared<DataEvent>(device, data));
        }
        queue->push(std::make_shared<WorkDoneEvent>(device));
    }

    std::shared_ptr<EventQueue> queue;
    std::shared_ptr<Device> A;
    std::shared_ptr<Device> B;
};

#endif // PARSER_H


