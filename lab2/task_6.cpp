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

    Student* students = new Student[numStudents];
    int* averages = new int[numStudents]; 

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter Name of Student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter Student " << i + 1 << " Roll No: ";
        cin >> students[i].rollNo;
        cout << "Enter Marks of First Subject of Student " << i + 1 << ": ";
        cin >> students[i].marks[0];
        cout << "Enter Marks of Second Subject of Student " << i + 1 << ": ";
        cin >> students[i].marks[1];
        cout << "Enter Marks of Third Subject of Student " << i + 1 << ": ";
        cin >> students[i].marks[2];
        averages[i] = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3; 
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "\nAverage of Student " << i + 1 << ":\n";
        cout << "Student Name: " << students[i].name << endl;
        cout << "Student Roll Number: " << students[i].rollNo << endl;
        cout << "Average in Three Subjects: " << averages[i] << endl;
    }

    delete[] averages;
    delete[] students;
    return 0;
}