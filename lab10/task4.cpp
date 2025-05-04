#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream file("vehicles.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;
        char comma;

        iss >> type >> id >> name >> yearStr >> comma >> extraData >> certification;
        int year = stoi(yearStr);

        if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':');
            string softwareVersionStr = extraData.substr(colonPos + 1);
            float softwareVersion = stof(softwareVersionStr);
            cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;
            cout << "Software Version: " << softwareVersion << endl;
        } else if (type == "ElectricVehicle") {
            size_t colonPos = extraData.find(':');
            string batteryCapacityStr = extraData.substr(colonPos + 1);
            int batteryCapacity = stoi(batteryCapacityStr);
            cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;
            cout << "Battery Capacity: " << batteryCapacity << endl;
        } else {
            cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;
            cout << "Extra Data: " << extraData << endl;
        }
        cout << "Certification: " << certification << endl;
    }

    file.close();
    return 0;
}