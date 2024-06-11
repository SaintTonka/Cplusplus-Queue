#include "EventQueue.h"

#include <queue>
#include <mutex>
#include <condition_variable>

EventQueue::EventQueue() : queue(), mutex(), cv() {} 

void EventQueue::push(const std::shared_ptr<const Event>& event) {
  std::lock_guard<std::mutex> lock(mutex);
  queue.push(event);
  cv.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds& duration) {
  std::unique_lock<std::mutex> lock(mutex);
  if (cv.wait_for(lock, duration, [this] { return !queue.empty(); })) {
    auto event = queue.front();
    queue.pop();
    return event;
  }
  return nullptr;
}