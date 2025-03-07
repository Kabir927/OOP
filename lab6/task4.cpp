#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    int accountNumber;
    float balance;

    Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    float interestRate;

    SavingsAccount(int accountNumber, float balance, float interestRate) 
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << ", Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account {
public:
    float overdraftLimit;

    CheckingAccount(int accountNumber, float balance, float overdraftLimit) 
        : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << ", Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings(12345, 5000, 2.5);
    CheckingAccount checking(67890, 3000, 1000);

    savings.displayDetails();
    checking.displayDetails();

    return 0;
}