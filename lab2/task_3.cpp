#include <iostream>
#include <string>

using namespace std;

struct Worker {
    string name;
    int hours;
    int rate;
};

void getData(Worker* emp, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter Name of Worker " << i + 1 << ": ";
        cin >> emp[i].name;
        cout << "Enter Hours Worked of Worker " << i + 1 << ": ";
        cin >> emp[i].hours;
        cout << "Enter Hourly Rate: ";
        cin >> emp[i].rate;
    }
}

void showSalaries(Worker* emp, int n) {
    cout << "\nCalculating Salaries:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nWorker Name: " << emp[i].name << endl;
        cout << "Salary: " << emp[i].hours * emp[i].rate << endl;
    }
}

int main() {
    int numWorkers;
    cout << "Enter the number of workers: ";
    cin >> numWorkers;

    Worker* workers = new Worker[numWorkers];

    getData(workers, numWorkers);
    showSalaries(workers, numWorkers);

    delete[] workers;
    return 0;
}