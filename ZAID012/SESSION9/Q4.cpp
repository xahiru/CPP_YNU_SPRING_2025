#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    
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
    
    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(12345, 1000);
    account.deposit(500);
    account.withdraw(200);
    account.displayBalance();
    return 0;
}
