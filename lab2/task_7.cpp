#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNo;
    double marks[3];
};

int main() {
    int numStudents;
    cout << "Enter Number of Students: ";
    cin >> numStudents;

    Student* studentData = new Student[numStudents];
    double* avgMarks = new double[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter Name of Student " << i + 1 << ": ";
        cin >> studentData[i].name;
        cout << "Enter Student " << i + 1 << " Roll No: ";
        cin >> studentData[i].rollNo;
        cout << "Enter Marks of First Subject of Student " << i + 1 << ": ";
        cin >> studentData[i].marks[0];
        cout << "Enter Marks of Second Subject of Student " << i + 1 << ": ";
        cin >> studentData[i].marks[1];
        cout << "Enter Marks of Third Subject of Student " << i + 1 << ": ";
        cin >> studentData[i].marks[2];
        avgMarks[i] = (studentData[i].marks[0] + studentData[i].marks[1] + studentData[i].marks[2]) / 3.0; 
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "\nAverage of Student " << i + 1 << ":\n";
        cout << "Student Name: " << studentData[i].name << endl;
        cout << "Student Roll Number: " << studentData[i].rollNo << endl;
        cout << "Average in Three Subjects: " << avgMarks[i] << endl;
    }

    delete[] avgMarks;
    delete[] studentData;
    return 0;
}