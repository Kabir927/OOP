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

        if (type == "HybridTruck") {
            size_t colonPos = extraData.find(':');
            size_t pipePos = extraData.find('|');
            string cargoStr = extraData.substr(colonPos + 1, pipePos - colonPos - 1);
            string batteryStr = extraData.substr(pipePos + 1);
            int cargo = stoi(cargoStr);
            int battery = stoi(batteryStr);
            cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;
            cout << "Cargo: " << cargo << ", Battery: " << battery << endl;
        } else {
            cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;
            cout << "Extra Data: " << extraData << endl;
        }
        cout << "Certification: " << certification << endl;
    }

    file.close();
    return 0;
}