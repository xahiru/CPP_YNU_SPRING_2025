#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance) 
        : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
        else cout << "Invalid deposit amount!" << endl;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
        else cout << "Invalid withdrawal amount!" << endl;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Account: " << accountNumber 
             << "\nBalance: $" << balance << endl;
    }
};

int main() {
    BankAccount acc("123456789", 1000.0);
    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.display();
    return 0;
}