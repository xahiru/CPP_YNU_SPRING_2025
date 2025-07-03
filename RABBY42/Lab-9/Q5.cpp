#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
public:
    BankAccount(string accNo, double bal) : accountNumber(accNo), balance(bal) {}
    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (balance >= amount) balance -= amount;
        else cout << "Insufficient balance!" << endl;
    }
    double getBalance() { return balance; }
};

int main() {
    BankAccount acc("123456", 1000);
    acc.withdraw(500);
    acc.deposit(200);
    cout << "Balance: $" << acc.getBalance() << endl; // $700
    return 0;
}