#include "Device.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include "EventQueue.h"
#include "Parser.h" 
#include <memory>

int main() {
  std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
  auto deviceB = std::make_shared<DeviceB>();
  auto eventQueue = std::make_shared<EventQueue>();
  Parser parser(eventQueue, deviceA, deviceB);
  parser.run(5, 5);
  return 0;
}