#include <iostream>

using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading temperature data." << endl;
    }
    
    void displayReport() override {
        cout << "Temperature: 22C" << endl;
    }
};

class Barometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading barometric pressure data." << endl;
    }
    
    void displayReport() override {
        cout << "Barometric Pressure: 1013 hPa" << endl;
    }
};

void processSensor(WeatherSensor* sensor) {
    sensor->readData();
    sensor->displayReport();
}

int main() {
    Thermometer thermometer;
    Barometer barometer;

    WeatherSensor* sensors[] = {&thermometer, &barometer};

    for (WeatherSensor* sensor : sensors) {
        processSensor(sensor);
    }

    return 0;
}