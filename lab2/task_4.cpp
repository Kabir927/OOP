#include <iostream>
#include <string>

using namespace std;

int main() {
    int numStrings;
    cout << "Enter Number of Strings: ";
    cin >> numStrings;

    string* strArray = new string[numStrings];

    for (int i = 0; i < numStrings; i++) {
        cout << "Enter String " << i + 1 << ": ";
        cin >> strArray[i];
    }

    for (int i = 0; i < numStrings - 1; i++) {
        if (strArray[i] > strArray[i + 1]) {
            string temp = strArray[i];
            strArray[i] = strArray[i + 1];
            strArray[i + 1] = temp;
            i = -1; 
        }
    }

    cout << "Sorted Strings:\n";
    for (int i = 0; i < numStrings; i++) {
        cout << "String " << i + 1 << ": " << strArray[i] << endl;
    }

    delete[] strArray;
    return 0;
}