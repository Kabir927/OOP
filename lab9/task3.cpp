#include <iostream>
#include <string>

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int creds) : courseCode(code), credits(creds) {}

    virtual ~Course() {}

    virtual int calculateGrade() = 0;
    virtual void displayInfo() = 0;

    string getCode() const { return courseCode; }
    int getCredits() const { return credits; }
};

class LectureCourse : public Course {
public:
    LectureCourse(string code, int creds) : Course(code, creds) {}

    int calculateGrade() override {
        cout << "Calculating grade for " << courseCode << endl;
        return 90;
    }

    void displayInfo() override {
        cout << "Course Code: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, int creds) : Course(code, creds) {}

    int calculateGrade() override {
        cout << "Calculating grade for " << courseCode << endl;
        return 85;
    }

    void displayInfo() override {
        cout << "Course Code: " << courseCode << ", Credits: " << credits << endl;
    }
};

int main() {
    LectureCourse lecture("CS101", 3);
    LabCourse lab("CS102", 4);

    Course* courses[2] = {&lecture, &lab};

    for (Course* course : courses) {
        course->displayInfo();
        cout << "Grade: " << course->calculateGrade() << endl;
        cout << endl;
    }

    return 0;
}