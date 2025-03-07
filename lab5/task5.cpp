#include <iostream>
#include <string>

using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string name, string specialization, int experience) 
        : name(name), specialization(specialization), experience(experience) {}
};

class Hospital {
public:
    string name;
    Doctor* doctors[10];
    int doctorCount;

    Hospital(string name) : name(name), doctorCount(0) {}

    void addDoctor(Doctor* doctor) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = doctor;
        }
    }

    void display() {
        cout << "Hospital: " << name << endl;
        cout << "Doctors: " << endl;
        for (int i = 0; i < doctorCount; ++i) {
            cout << "Name: " << doctors[i]->name << ", Specialization: " << doctors[i]->specialization << ", Experience: " << doctors[i]->experience << " years" << endl;
        }
    }
};

int main() {
    Doctor doc1("John Doe", "Cardiology", 10);
    Doctor doc2("Jane Smith", "Pediatrics", 8);

    Hospital hospital("City General");

    hospital.addDoctor(&doc1);
    hospital.addDoctor(&doc2);

    hospital.display();

    return 0;
}