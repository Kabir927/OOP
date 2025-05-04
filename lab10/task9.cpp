#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("large_log.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    char buffer[100];
    file.read(buffer, 10);
    cout << "First 10 characters: " << buffer << endl;
    cout << "Current position: " << file.tellg() << endl;

    file.read(buffer, 10);
    cout << "Next 10 characters: " << buffer << endl;
    cout << "Current position: " << file.tellg() << endl;

    file.close();
    return 0;
}