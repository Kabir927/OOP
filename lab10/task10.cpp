#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream file("data_records.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return 1;
    }
    file << "Record 1\n";
    file << "Record 2\n";
    file << "Record 3\n";
    file << "Record 4\n";
    file.close();


    ifstream readFile("data_records.txt");
    if (!readFile.is_open()) {
        cerr << "Failed to open file for reading." << endl;
        return 1;
    }



    const int recordLength = 9;
    const int offsetToThirdRecord = 2 * recordLength;


    readFile.seekg(offsetToThirdRecord, ios::beg);


    string line;
    if (getline(readFile, line)) {
        cout << "Content of the third record: " << line << endl;
    }


    readFile.close();

    return 0;
}