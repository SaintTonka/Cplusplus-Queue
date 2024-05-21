#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <string>
#include <thread>
#include <sstream>
#include <stdexcept>

// Event interface
class Event
{
public:
    virtual ~Event() = default;
    virtual std::string toString() const = 0;
};

// Device interface
class Device
{
public:
    virtual ~Device() = default;
    virtual std::string getName() const = 0;
    virtual std::string getDataAsString() const = 0;
};

// DeviceEvent class
class DeviceEvent : public Event
{
public:
    DeviceEvent(const std::shared_ptr<const Device>& device) : device(device) {}
    std::shared_ptr<const Device> getDevice() const { return device; }

private:
    std::shared_ptr<const Device> device;
};

// DataEvent class
class DataEvent : public DeviceEvent
{
public:
    DataEvent(const std::shared_ptr<const Device>& device, const std::string& data)
        : DeviceEvent(device), data(data) {}
    std::string toString() const override { return "DataEvent: " + data; }

private:
    std::string data;
};

// WorkDoneEvent class
class WorkDoneEvent : public DeviceEvent
{
public:
    WorkDoneEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {}
    std::string toString() const override { return "WorkDoneEvent"; }
};

// StartedEvent class
class StartedEvent : public DeviceEvent
{
public:
    StartedEvent(const std::shared_ptr<const Device>& device) : DeviceEvent(device) {}
    std::string toString() const override { return "StartedEvent"; }
};

// DeviceA class
class DeviceA : public Device
{
public:
    std::string getName() const override { return "A"; }
    std::string getDataAsString() const override
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return "String from DeviceA";
    }
};

// DeviceB class
class DeviceB : public Device
{
public:
    std::string getName() const override { return "B"; }
    std::string getDataAsString() const override
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return "1 2 3";
    }
};

// EventQueue class
class EventQueue
{
public:
    void push(const std::shared_ptr<const Event>& event)
    {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(event);
        cv.notify_one();
    }

    std::shared_ptr<const Event> pop(const std::chrono::seconds& duration)
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (cv.wait_for(lock, duration, [this] { return !queue.empty(); }))
        {
            auto event = queue.front();
            queue.pop();
            return event;
        }
        return nullptr;
    }

private:
    std::queue<std::shared_ptr<const Event>> queue;
    std::mutex mtx;
    std::condition_variable cv;
};

// Read thread function for DeviceA
void readThreadA(EventQueue& eventQueue, const std::shared_ptr<const Device>& deviceA, int maxAttempts)
{
    int attempts = 0;
    while (attempts < maxAttempts)
    {
        try
        {
            auto data = deviceA->getDataAsString();
            eventQueue.push(std::make_shared<DataEvent>(deviceA, data));
            attempts = 0;
        }
        catch (...)
        {
            std::cerr << "Error reading from DeviceA" << std::endl;
            attempts++;
        }
    }
    eventQueue.push(std::make_shared<WorkDoneEvent>(deviceA));
}

// Read thread function for DeviceB
void readThreadB(EventQueue& eventQueue, const std::shared_ptr<const Device>& deviceB, int maxAttempts)
{
    int attempts = 0;
    while (attempts < maxAttempts)
    {
        try
        {
            auto data = deviceB->getDataAsString();
            eventQueue.push(std::make_shared<DataEvent>(deviceB, data));
            attempts = 0;
        }
        catch (...)
        {
            std::cerr << "Error reading from DeviceB" << std::endl;
            attempts++;
        }
    }
    eventQueue.push(std::make_shared<WorkDoneEvent>(deviceB));
}

// Parser class
class Parser
{
public:
    Parser(const std::shared_ptr<EventQueue>& queue, const std::shared_ptr<const Device>& deviceA, const std::shared_ptr<const Device>& deviceB)
        : queue(queue), deviceA(deviceA), deviceB(deviceB)
    {
        if (!queue || !deviceA || !deviceB)
        {
            throw std::runtime_error("Invalid input parameters");
        }
    }

    void run(int maxAttemptsA, int maxAttemptsB, int timeoutSeconds = 5, int sleepSeconds = 1)
    {
        std::thread threadA(readThreadA, std::ref(*queue), deviceA, maxAttemptsA);
        std::thread threadB(readThreadB, std::ref(*queue), deviceB, maxAttemptsB);

        queue->push(std::make_shared<StartedEvent>(deviceA));
        queue->push(std::make_shared<StartedEvent>(deviceB));

        bool isDeviceAWorking = true;
        bool isDeviceBWorking = true;

        while (true)
        {
            auto event = queue->pop(std::chrono::seconds(timeoutSeconds));
            if (event == nullptr)
            {
                std::cerr << "No events received for " << timeoutSeconds << " seconds, exiting" << std::endl;
                break;
            }
            // Use dynamic_cast to check for DeviceEvent and access getDevice()
            else if (auto deviceEvent = dynamic_cast<const DeviceEvent*>(event.get()))
            {
                if (event->toString() == "WorkDoneEvent")
                {
                    if (deviceEvent->getDevice()->getName() == "A")
                    {
                        isDeviceAWorking = false;
                    }
                    else if (deviceEvent->getDevice()->getName() == "B")
                    {
                        isDeviceBWorking = false;
                    }
                    if (!isDeviceAWorking && !isDeviceBWorking)
                    {
                        std::cerr << "Both devices failed, exiting" << std::endl;
                        break;
                    }
                }
                else if (event->toString() == "StartedEvent")
                {
                    std::cout << "Started: " << deviceEvent->getDevice()->getName() << std::endl;
                }
            }
            else
            {
                std::cout << event->toString() << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::seconds(sleepSeconds));
        }

        threadA.join();
        threadB.join();
    }

private:
    std::shared_ptr<EventQueue> queue;
    std::shared_ptr<const Device> deviceA;
    std::shared_ptr<const Device> deviceB;
};

int main()
{
    // Create a shared pointer to an EventQueue
    auto queue = std::make_shared<EventQueue>();

    // Create shared pointers to DeviceA and DeviceB
    auto deviceA = std::make_shared<DeviceA>();
    auto deviceB = std::make_shared<DeviceB>();

    // Create a Parser object with the EventQueue and devices
    Parser parser(queue, deviceA, deviceB);

    // Run the parser with different configurations
    std::cout << "Running with both devices working normally..." << std::endl;
    parser.run(1, 1);

    std::cout << "Running with DeviceA failing after 2 attempts..." << std::endl;
    parser.run(2, 1, 1, 1);

    std::cout << "Running with DeviceB failing after 2 attempts..." << std::endl;
    parser.run(1, 2, 1, 1);

    std::cout << "Running with both devices failing after 2 attempts..." << std::endl;
    parser.run(2, 2, 1, 1);

    return 0;
}