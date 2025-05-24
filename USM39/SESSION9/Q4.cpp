#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account("123456789", 1000);
    account.deposit(500);
    account.withdraw(200);
    cout << "Balance: " << account.getBalance() << endl;
    return 0;
}
