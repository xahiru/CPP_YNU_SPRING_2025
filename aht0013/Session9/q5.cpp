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
        if (amount > 0) {
            balance += amount;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
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
    cout << "Current balance: " << account.getBalance() << endl;
    return 0;
}