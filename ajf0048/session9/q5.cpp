#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account("123456789", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);
    cout << "Current Balance: " << account.getBalance() << endl;
    return 0;
}