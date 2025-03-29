#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr) 
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }

    virtual void updateInfo(string n, int a, string contact, string addr) {
        name = n;
        age = a;
        contactNumber = contact;
        address = addr;
    }
};

class Patient : public Person {
private:
    string patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, string addr, string id, string history, string doctor) 
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    float consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string contact, string addr, string spec, float fee, string patients) 
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), patientsList(patients) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        cout << "Patients List: " << patientsList << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift) 
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    float salary;

public:
    Administrator(string n, int a, string contact, string addr, string dept, float sal) 
        : Person(n, a, contact, addr), department(dept), salary(sal) {}

    void updateInfo(string n, int a, string contact, string addr) override {
        Person::updateInfo(n, a, contact, addr);
        cout << "Administrator record updated." << endl;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Patient patient("John Doe", 35, "1234567890", "123 Main St", "P001", "None", "Dr. Smith");
    Doctor doctor("Dr. Smith", 45, "9876543210", "456 Oak St", "Cardiology", 150.0, "P001, P002");
    Nurse nurse("Nurse Jane", 30, "5551234567", "789 Pine St", "ICU", "Night Shift");
    Administrator admin("Admin Bob", 50, "9998887777", "321 Elm St", "HR", 5000.0);

    patient.displayInfo();
    doctor.displayInfo();
    nurse.displayInfo();
    admin.displayInfo();

    admin.updateInfo("Admin Robert", 51, "9998887777", "321 Elm St");
    admin.displayInfo();

    return 0;
}