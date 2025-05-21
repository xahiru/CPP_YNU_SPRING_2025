#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
public:
    void setAccountNumber(string accNum) {
        accountNumber = accNum;
    }
    void deposit(double amount) {
        balance += amount;
    }
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc;
    acc.setAccountNumber("123456789");
    acc.deposit(1000.0);
    
    if (acc.withdraw(500.0)) {
        cout << "Withdrawal successful. New balance: " << acc.getBalance() << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
    
    return 0;
}
