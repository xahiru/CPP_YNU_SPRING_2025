#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc("123456789", 1000.0);
    acc.deposit(500.0);
    acc.withdraw(200.0);
    cout << "Current Balance: $" << acc.getBalance() << endl;
    return 0;
}