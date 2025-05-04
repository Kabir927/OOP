#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
        string type, id, name, year, extraData, certification;
        char comma;

        iss >> type >> id >> name >> year >> comma >> extraData >> certification;
        cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;
        cout << "Extra Data: " << extraData << ", Certification: " << certification << endl;
    }

    file.close();
    return 0;
}