#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
public:
    void setAccount(string acc, double bal) {
        accountNumber = acc;
        balance = bal;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient funds!" << endl;
    }
    double getBalance() { return balance; }
};

int main() {
    BankAccount acc;
    acc.setAccount("123456", 1000.0);
    acc.deposit(500.0);
    acc.withdraw(200.0);
    cout << "Balance: $" << acc.getBalance() << endl;
    return 0;
}