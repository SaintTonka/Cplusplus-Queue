#include "StartedEvent.h"
#include "WorkDoneEvent.h"
#include "DataEvent.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include <gtest/gtest.h>

TEST(Events, StartedEventTest)
{
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  EXPECT_EQ(StartedEvent(A).toString(), "StartedEvent: Device: DeviceA");
  EXPECT_EQ(StartedEvent(B).toString(), "StartedEvent: Device: DeviceB");
}

TEST(Events, DataEventTest)
{
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  DataEvent dataEventA(A, A->getDataAsString());
  DataEvent dataEventB(B, B->getDataAsString());

  EXPECT_TRUE(dataEventA.toString().find("DataEvent: Device: DeviceA, Data:") != std::string::npos);
  EXPECT_TRUE(dataEventB.toString().find("DataEvent: Device: DeviceB, Data:") != std::string::npos);
}

TEST(Events, WorkDoneEventTest)
{
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  EXPECT_EQ(WorkDoneEvent(A).toString(), "WorkDoneEvent: Device: DeviceA");
  EXPECT_EQ(WorkDoneEvent(B).toString(), "WorkDoneEvent: Device: DeviceB");
}
