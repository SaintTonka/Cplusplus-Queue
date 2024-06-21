#include "../src/Parser.h"

#include "EventQueue.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include <gtest/gtest.h>
#include <sstream>
#include <functional>

namespace {
  std::string captureOutput(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
  }
}

TEST(Parser, RunDefaultTest) {
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(1, 1); });
  std::cout << stream << std::endl;

  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceA") != std::string::npos);
  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceB") != std::string::npos);
  EXPECT_TRUE(stream.find("WorkDoneEvent: Device: DeviceA") != std::string::npos);
  EXPECT_TRUE(stream.find("WorkDoneEvent: Device: DeviceB") != std::string::npos);
}

TEST(Parser, RunCrushATest) {
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(2, 1, 1); });

  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceA") != std::string::npos);
  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceB") != std::string::npos);
  EXPECT_TRUE(stream.find("WorkDoneEvent: Device: DeviceB") != std::string::npos);
}

TEST(Parser, RunCrushBTest) {
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(1, 2, -1, 1); });

  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceA") != std::string::npos);
  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceB") != std::string::npos);
  EXPECT_TRUE(stream.find("WorkDoneEvent: Device: DeviceA") != std::string::npos);
}

TEST(Parser, RunCrushABTest) {
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(2, 2, 1, 1); });

  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceA") != std::string::npos);
  EXPECT_TRUE(stream.find("StartedEvent: Device: DeviceB") != std::string::npos);
}