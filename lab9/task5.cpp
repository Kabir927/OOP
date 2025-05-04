#include <iostream>
#include <string>

using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;
public:
    virtual void estimatedDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    void estimatedDeliveryTime() override {
        cout << "Estimated delivery time for air freight: 2 days" << endl;
    }
    
    void showDetails() override {
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Delivery Time: 2 days" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    void estimatedDeliveryTime() override {
        cout << "Estimated delivery time for ground shipment: 5 days" << endl;
    }
    
    void showDetails() override {
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Delivery Time: 5 days" << endl;
    }
};

void processShipment(Shipment* shipment) {
    shipment->showDetails();
    shipment->estimatedDeliveryTime();
}

int main() {
    AirFreight airFreight;
    airFreight.trackingNumber = "ABC123";
    airFreight.weight = 10.5;

    GroundShipment groundShipment;
    groundShipment.trackingNumber = "XYZ789";
    groundShipment.weight = 20.0;

    processShipment(&airFreight);
    processShipment(&groundShipment);

    return 0;
}