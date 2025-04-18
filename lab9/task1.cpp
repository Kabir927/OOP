
#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
    virtual ~Patient() {}
};

class InPatient : public Patient {
private:
    int daysStayed;
    double dailyRate;
    string treatmentType;

public:
    InPatient(string n, string i, int days, double rate, string treatment)
        : Patient(n, i), daysStayed(days), dailyRate(rate), treatmentType(treatment) {}

    void displayTreatment() override {
        cout << "InPatient Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Treatment: " << treatmentType << endl;
        cout << "Days Stayed: " << daysStayed << endl;
    }

    double calculateCost() override {
        return daysStayed * dailyRate;
    }
};

class OutPatient : public Patient {
private:
    string procedure;
    double procedureCost;

public:
    OutPatient(string n, string i, string proc, double cost)
        : Patient(n, i), procedure(proc), procedureCost(cost) {}

    void displayTreatment() override {
        cout << "OutPatient Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Procedure: " << procedure << endl;
    }

    double calculateCost() override {
        return procedureCost;
    }
};

int main() {
    Patient* patients[2];
    
    patients[0] = new InPatient("John Doe", "IP001", 5, 1000.0, "Surgery");
    patients[1] = new OutPatient("Jane Smith", "OP001", "Consultation", 200.0);

    for(int i = 0; i < 2; i++) {
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << endl;
        cout << "------------------------" << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete patients[i];
    }

    return 0;
}
