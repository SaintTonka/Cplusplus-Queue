#include "gtest/gtest.h"
#include "Device.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include <memory>

TEST(DeviceA_GetNameTest, TestBody) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    ASSERT_EQ(deviceA->getName(), "DeviceA_Mock");
}

TEST(DeviceA_GetDataTest, TestBody) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    ASSERT_EQ(deviceA->getDataAsString(), "DeviceA_Mock_Data");
}

TEST(DeviceB_GetNameTest, TestBody) {
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    ASSERT_EQ(deviceB->getName(), "DeviceB_Mock");
}

TEST(DeviceB_GetDataTest, TestBody) {
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    ASSERT_EQ(deviceB->getDataAsString(), "DeviceB_Mock_Data");
}
