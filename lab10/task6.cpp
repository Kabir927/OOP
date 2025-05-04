#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item = {101, "Laptop"};
    ofstream file("inventory.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return 1;
    }
    file.write(reinterpret_cast<const char*>(&item), sizeof(item));
    file.close();

    ifstream readFile("inventory.dat", ios::binary);
    if (!readFile.is_open()) {
        cerr << "Failed to open file for reading." << endl;
        return 1;
    }
    InventoryItem loadedItem;
    readFile.read(reinterpret_cast<char*>(&loadedItem), sizeof(loadedItem));
    readFile.close();

    cout << "Item ID: " << loadedItem.itemID << ", Item Name: " << loadedItem.itemName << endl;
    return 0;
}
