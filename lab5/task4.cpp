#include <iostream>
#include <string>

using namespace std;

class AlarmSystem {
public:
    string securityLevel;

    AlarmSystem(string level) : securityLevel(level) {}
};

class SmartHome {
public:
    string homeName;
    AlarmSystem alarm;

    SmartHome(string name, string alarmLevel) : homeName(name), alarm(alarmLevel) {}

    void display() {
        cout << "Smart Home: " << homeName << endl;
        cout << "Alarm System Security Level: " << alarm.securityLevel << endl;
    }
};

int main() {
    SmartHome home("Modern Villa", "High");
    home.display();

    return 0;
}