#pragma once

#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Event.h"

class EventQueue {
public:
    void push(std::shared_ptr<Event> event);
    std::shared_ptr<Event> pop(std::chrono::milliseconds timeout);

private:
    std::queue<std::shared_ptr<Event>> queue;
    std::mutex mtx;
    std::condition_variable cv;
};

