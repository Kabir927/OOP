
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    double balance;
    friend class Manager;
    friend bool transferFunds(Account& from, Account& to, double amount);

public:
    Account(string accNum, double initialBalance = 0.0) : accountNumber(accNum), balance(initialBalance) {}
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << endl;
        cout << "Balance: $" << acc.balance << endl;
    }

    bool deposit(Account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(Account& acc, double amount) {
        if (amount > 0 && acc.balance >= amount) {
            acc.balance -= amount;
            return true;
        }
        return false;
    }
};

bool transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        return true;
    }
    return false;
}

int main() {
    Account acc1("ACC001", 1000);
    Account acc2("ACC002", 500);
    Manager manager;

    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    manager.deposit(acc1, 500);
    cout << "\nAfter depositing $500 to ACC001:" << endl;
    manager.displayAccount(acc1);

    manager.withdraw(acc2, 200);
    cout << "\nAfter withdrawing $200 from ACC002:" << endl;
    manager.displayAccount(acc2);

    transferFunds(acc1, acc2, 300);
    cout << "\nAfter transferring $300 from ACC001 to ACC002:" << endl;
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    return 0;
}
