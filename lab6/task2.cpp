#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    string brand;
    int speed;

    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << endl;
    }
};

class Car : public Vehicle {
public:
    int seats;

    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << ", Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
public:
    int batteryLife;

    ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << ", Seats: " << seats << ", Battery Life: " << batteryLife << endl;
    }
};

int main() {
    ElectricCar ecar("Tesla", 250, 5, 300);
    ecar.displayDetails();

    return 0;
}