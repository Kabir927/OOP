#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int* examScores;
    int numScores;

public:
    Student(int id, string name, int scores[], int numScores) {
        this->id = id;
        this->name = name;
        this->numScores = numScores;
        this->examScores = new int[numScores];
        for (int i = 0; i < numScores; ++i) {
            this->examScores[i] = scores[i];
        }
    }

    Student(const Student &other) {
        this->id = other.id;
        this->name = other.name;
        this->numScores = other.numScores;
        this->examScores = new int[other.numScores];
        for (int i = 0; i < other.numScores; ++i) {
            this->examScores[i] = other.examScores[i];
        }
    }

    ~Student() {
        delete[] examScores;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Scores: ";
        for (int i = 0; i < numScores; ++i) {
            cout << examScores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int scores1[] = {85, 90, 78};
    Student student1(1, "Alice", scores1, 3);

    Student student2 = student1;

    student1.display();
    student2.display();

    return 0;
}