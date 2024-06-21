#ifndef PARSER_H
#define PARSER_H

#include "EventQueue.h"
#include "Device.h"
#include <memory>
#include <chrono>

class Parser {
public:
    Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> A, std::shared_ptr<Device> B);
    void run(size_t loop_count_A, size_t loop_count_B, int crush_index_A = -1, int crush_index_B = -1);

private:
    void read(std::shared_ptr<Device> device, std::chrono::seconds sleep_duration, size_t loop_count, int crush_index);

    std::shared_ptr<EventQueue> queue;
    std::shared_ptr<Device> A;
    std::shared_ptr<Device> B;
};

#endif 
