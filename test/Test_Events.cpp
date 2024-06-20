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

    EXPECT_EQ(StartedEvent(std::move(A)).toString(), "StartedEvent: Device: DeviceA");
    EXPECT_EQ(StartedEvent(std::move(B)).toString(), "StartedEvent: Device: DeviceB");
}

TEST(Events, DataEventTest)
{
    std::shared_ptr<Device> A = std::make_shared<DeviceA>();
    std::shared_ptr<Device> B = std::make_shared<DeviceB>();

    std::string stringA = DataEvent(std::move(A)).toString();
    std::string stringB = DataEvent(std::move(B)).toString();

    std::string tailA = " from A";
    std::string tailB = " from B";

    EXPECT_TRUE(stringA.substr(stringA.size() - tailA.size()) == tailA);
    EXPECT_TRUE(stringB.substr(stringB.size() - tailB.size()) == tailB);
}

TEST(Events, WorkDoneEventTest)
{
    std::shared_ptr<Device> A = std::make_shared<DeviceA>();
    std::shared_ptr<Device> B = std::make_shared<DeviceB>();

    EXPECT_EQ(WorkDoneEvent(std::move(A)).toString(), "WorkDoneEvent: Device: DeviceA");
    EXPECT_EQ(WorkDoneEvent(std::move(B)).toString(), "WorkDoneEvent: Device: DeviceB");
}
