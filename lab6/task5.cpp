#include <iostream>
#include <string>

using namespace std;

class Device {
public:
    int deviceID;
    bool status;

    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    void displayDetails() {
        cout << "Device ID: " << deviceID << ", Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : public Device {
public:
    float screenSize;

    SmartPhone(int deviceID, bool status, float screenSize) 
        : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails() {
        cout << "Device ID: " << deviceID << ", Status: " << (status ? "On" : "Off") << ", Screen Size: " << screenSize << endl;
    }
};

class SmartWatch : public Device {
public:
    bool heartRateMonitor;

    SmartWatch(int deviceID, bool status, bool heartRateMonitor) 
        : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() {
        cout << "Device ID: " << deviceID << ", Status: " << (status ? "On" : "Off") << ", Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
public:
    int stepCounter;

    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
        : SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() {
        cout << "Device ID: " << SmartPhone::deviceID << ", Status: " << (SmartPhone::status ? "On" : "Off") << ", Screen Size: " << screenSize << ", Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << ", Step Counter: " << stepCounter << endl;
    }
};

int main() {
    SmartWearable wearable(101, true, 6.1, true, 5000);
    wearable.displayDetails();

    return 0;
}