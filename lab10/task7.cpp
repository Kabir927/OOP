#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("sensor_log.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    file << "Sensor 1: 25.5 C" << endl;
    file << "Sensor 2: 98.1 %RH" << endl;
    file.close();
    return 0;
}