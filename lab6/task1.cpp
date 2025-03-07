#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string name;
    float salary;

    Employee(string name, float salary) : name(name), salary(salary) {}

    void displayDetails() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee {
public:
    float bonus;

    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails() {
        cout << "Name: " << name << ", Salary: " << salary << ", Bonus: " << bonus << endl;
    }
};

int main() {
    Manager mgr("John Doe", 5000, 1000);
    mgr.displayDetails();

    return 0;
}