#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person {
public:
    string subject;

    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

class Researcher : public Person {
public:
    string researchArea;

    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
public:
    int publications;

    Professor(string name, int age, string subject, string researchArea, int publications)
        : Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() {
        cout << "Name: " << Teacher::name << ", Age: " << Teacher::age << ", Subject: " << subject << ", Research Area: " << researchArea << ", Publications: " << publications << endl;
    }
};

int main() {
    Professor prof("John Doe", 45, "Computer Science", "Artificial Intelligence", 20);
    prof.displayDetails();

    return 0;
}