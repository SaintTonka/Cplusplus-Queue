#include "gtest/gtest.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include <memory>
#include <algorithm>

TEST(DeviceA_GetNameTest, TestBody) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    ASSERT_EQ(deviceA->getName(), "DeviceA");
}

TEST(DeviceA_GetDataTest, TestBody) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    std::string data = deviceA->getDataAsString();
    static const std::string alphanum =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    
    ASSERT_LE(data.size(), 50);
    ASSERT_GE(data.size(), 0);

    
    ASSERT_FALSE(data.empty());
}

TEST(DeviceB_GetNameTest, TestBody) {
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    ASSERT_EQ(deviceB->getName(), "DeviceB");
}

TEST(DeviceB_GetDataTest, TestBody) {
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    std::string data = deviceB->getDataAsString();
    std::stringstream ss(data);
    int a, b, c;
    ss >> a >> b >> c;
    ASSERT_GE(a, 0);
    ASSERT_LE(a, 198);
    ASSERT_GE(b, 0);
    ASSERT_LE(b, 198);
    ASSERT_GE(c, 0);
    ASSERT_LE(c, 198);
}
