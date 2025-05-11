
#include <iostream>
#include <string>
using namespace std;

class NegativeStockException : public exception {};

class OverCapacityException : public exception {};

template<typename T>
class InventoryItem {
private:
    T stock;
    T maxCapacity;

public:
    InventoryItem(T capacity = 100) : stock(0), maxCapacity(capacity) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxCapacity) {
            throw OverCapacityException();
        }
        stock = newStock;
    }

    T getStock() const {
        return stock;
    }

    T getMaxCapacity() const {
        return maxCapacity;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    }
    catch (const NegativeStockException&) {
        cout << "Caught NegativeStockException - what(): std::exception" << endl;
    }

    try {
        cout << "\nAttempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    }
    catch (const OverCapacityException&) {
        cout << "Caught OverCapacityException - what(): std::exception" << endl;
    }

    return 0;
}
