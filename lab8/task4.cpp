
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double price;
    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
public:
    Car(string m, double p) : model(m), price(p) {}
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }

    void displayDetails(const Car& car) {
        cout << "Model: " << car.model << endl;
        cout << "Price: $" << car.price << endl;
    }
};

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive by $" << car1.price - car2.price << endl;
    } else if (car2.price > car1.price) {
        cout << car2.model << " is more expensive by $" << car2.price - car1.price << endl;
    } else {
        cout << "Both cars have the same price of $" << car1.price << endl;
    }
}

int main() {
    Car car1("Toyota Camry", 25000);
    Car car2("Honda Accord", 27000);
    
    InventoryManager manager;
    
    cout << "Initial car details:" << endl;
    manager.displayDetails(car1);
    manager.displayDetails(car2);
    
    manager.updatePrice(car1, 26000);
    
    cout << "\nAfter price update:" << endl;
    manager.displayDetails(car1);
    
    cout << "\nPrice comparison:" << endl;
    comparePrice(car1, car2);
    
    return 0;
}
