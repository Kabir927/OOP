#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string name;
    string designation;

    Employee(string name, string designation) : name(name), designation(designation) {}
};

class Project {
public:
    string title;
    string deadline;
    Employee* employees[10];
    int employeeCount;

    Project(string title, string deadline) : title(title), deadline(deadline), employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < 10) {
            employees[employeeCount++] = employee;
        }
    }

    void display() {
        cout << "Project: " << title << ", Deadline: " << deadline << endl;
        cout << "Assigned Employees: " << endl;
        for (int i = 0; i < employeeCount; ++i) {
            cout << "Name: " << employees[i]->name << ", Designation: " << employees[i]->designation << endl;
        }
    }
};

int main() {
    Employee emp1("John Doe", "Developer");
    Employee emp2("Jane Smith", "Designer");

    Project proj1("Website Redesign", "2025-12-01");
    Project proj2("Mobile App Development", "2025-11-15");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj2.addEmployee(&emp1);

    proj1.display();
    proj2.display();

    return 0;
}