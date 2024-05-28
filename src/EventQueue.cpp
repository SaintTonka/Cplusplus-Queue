#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Event.h"

class EventQueue {
public:
    void push(const std::shared_ptr<const Event> &event) {
        std::lock_guard<std::mutex> lock(mutex);
        queue.push(event);
        cv.notify_one();
    }

    std::shared_ptr<const Event> pop(const std::chrono::seconds &duration) {
        std::unique_lock<std::mutex> lock(mutex);
        if (cv.wait_for(lock, duration, [this] { return !queue.empty(); })) {
            auto event = queue.front();
            queue.pop();
            return event;
        }
        return nullptr;
    }

private:
    std::queue<std::shared_ptr<const Event>> queue;
    std::mutex mutex;
    std::condition_variable cv;
};
