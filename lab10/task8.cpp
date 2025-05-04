#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ofstream file("config.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    file << "AAAAABBBBCCCCC";
    file.close();

    ifstream readFile("config.txt", ios::in | ios::out);
    if (!readFile.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    char buffer[100];
    readFile.read(buffer, 5);
    readFile.seekp(5, ios::beg);
    readFile.write("XXXXX", 5);
    readFile.close();

    readFile.open("config.txt");
    readFile.read(buffer, sizeof(buffer));
    readFile.close();

    cout << "Updated Config: " << buffer << endl;
    return 0;
}