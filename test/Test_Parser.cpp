#include "../src/Parser.h"

#include "gtest/gtest.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include <memory>
#include <sstream>

TEST(DeviceA_GetNameTest, TestBody) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    ASSERT_EQ(deviceA->getName(), "DeviceA");
}

TEST(DeviceA_GetDataTest, TestBody) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    std::string data = deviceA->getDataAsString();
    ASSERT_LE(data.size(), 50);
    ASSERT_GE(data.size(), 10);
    static const std::string alphanum =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    for (char c : data) {
        ASSERT_TRUE(alphanum.find(c) != std::string::npos);
    }
}

// Тесты для DeviceB
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

// Тесты для Parser
TEST(ParserTest, RunDefaultTest) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    Parser parser;
    
    testing::internal::CaptureStdout();
    parser.process(deviceA);
    parser.process(deviceB);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_NE(output.find("StartedEvent: Device: DeviceA"), std::string::npos);
    ASSERT_NE(output.find("DataEvent: Device: DeviceA, Data: "), std::string::npos);
    ASSERT_NE(output.find("WorkDoneEvent: Device: DeviceA"), std::string::npos);
    ASSERT_NE(output.find("StartedEvent: Device: DeviceB"), std::string::npos);
    ASSERT_NE(output.find("DataEvent: Device: DeviceB, Data: "), std::string::npos);
    ASSERT_NE(output.find("WorkDoneEvent: Device: DeviceB"), std::string::npos);
}

TEST(ParserTest, RunCrushATest) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    Parser parser;
    
    testing::internal::CaptureStdout();
    parser.process(deviceA);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_NE(output.find("StartedEvent: Device: DeviceA"), std::string::npos);
    ASSERT_NE(output.find("DataEvent: Device: DeviceA, Data: "), std::string::npos);
    ASSERT_NE(output.find("WorkDoneEvent: Device: DeviceA"), std::string::npos);
}

TEST(ParserTest, RunCrushBTest) {
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    Parser parser;
    
    testing::internal::CaptureStdout();
    parser.process(deviceB);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_NE(output.find("StartedEvent: Device: DeviceB"), std::string::npos);
    ASSERT_NE(output.find("DataEvent: Device: DeviceB, Data: "), std::string::npos);
    ASSERT_NE(output.find("WorkDoneEvent: Device: DeviceB"), std::string::npos);
}

TEST(ParserTest, RunCrushABTest) {
    std::shared_ptr<DeviceA> deviceA = std::make_shared<DeviceA>();
    std::shared_ptr<DeviceB> deviceB = std::make_shared<DeviceB>();
    Parser parser;
    
    testing::internal::CaptureStdout();
    parser.process(deviceA);
    parser.process(deviceB);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_NE(output.find("StartedEvent: Device: DeviceA"), std::string::npos);
    ASSERT_NE(output.find("DataEvent: Device: DeviceA, Data: "), std::string::npos);
    ASSERT_NE(output.find("WorkDoneEvent: Device: DeviceA"), std::string::npos);
    ASSERT_NE(output.find("StartedEvent: Device: DeviceB"), std::string::npos);
    ASSERT_NE(output.find("DataEvent: Device: DeviceB, Data: "), std::string::npos);
    ASSERT_NE(output.find("WorkDoneEvent: Device: DeviceB"), std::string::npos);
}