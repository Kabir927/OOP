#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(string id, string name, string loc) : deviceID(id), deviceName(name), location(loc), status(false) {}

    void turnOn() {
        status = true;
    }

    void turnOff() {
        status = false;
    }

    bool getStatus() {
        return status;
    }

    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Location: " << location << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(string id, string name, string loc, int brightness, string color) 
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(string id, string name, string loc, float temp, string m, float target) 
        : Device(id, name, loc), temperature(temp), mode(m), targetTemperature(target) {}

    bool getStatus() {
        cout << "Current Temperature: " << temperature << endl;
        return status;
    }

    void displayInfo() override {
        Device::displayInfo();
        cout << "Temperature: " << temperature << endl;
        cout << "Mode: " << mode << endl;
        cout << "Target Temperature: " << targetTemperature << endl;
    }
};

class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(string id, string name, string loc, string res, bool nightVision) 
        : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}

    void turnOn() override {
        status = true;
        recordingStatus = true;
    }

    void displayInfo() override {
        Device::displayInfo();
        cout << "Resolution: " << resolution << endl;
        cout << "Recording Status: " << (recordingStatus ? "Recording" : "Not Recording") << endl;
        cout << "Night Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled") << endl;
    }
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(string id, string name, string loc, float power, int timer) 
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override {
        status = false;
        cout << "Power Consumed: " << powerConsumption << " kWh" << endl;
    }

    void displayInfo() override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption << " kWh" << endl;
        cout << "Timer Setting: " << timerSetting << " minutes" << endl;
    }
};

int main() {
    Light light("L001", "Living Room Light", "Living Room", 75, "Warm");
    Thermostat thermo("T001", "Living Room Thermostat", "Living Room", 22.5, "Cooling", 20.0);
    SecurityCamera camera("C001", "Front Door Camera", "Front Door", "1080p", true);
    SmartPlug plug("P001", "Coffee Maker Plug", "Kitchen", 1.5, 30);

    light.turnOn();
    thermo.turnOn();
    camera.turnOn();
    plug.turnOn();

    light.displayInfo();
    thermo.displayInfo();
    camera.displayInfo();
    plug.displayInfo();

    plug.turnOff();

    return 0;
}