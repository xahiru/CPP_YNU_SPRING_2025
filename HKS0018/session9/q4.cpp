#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance) {     // Constructor to initialize account
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid deposit amount. Amount must be positive." << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrew $" << amount << " successfully." << endl;
            } else {
                cout << "Insufficient balance. Cannot withdraw $" << amount << endl;
            }
        } else {
            cout << "Invalid withdrawal amount. Amount must be positive." << endl;
        }
    }
    void display() const {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount("123456789", 1000.0);

    cout << "Initial Account Information:";
    myAccount.display();

    myAccount.deposit(500.0);       // Perform deposits
    myAccount.deposit(-100.0);  // Invalid deposit

    myAccount.withdraw(200.0);
    myAccount.withdraw(2000.0); // Attempt to overdraw
    myAccount.withdraw(-50.0);  // Invalid withdrawal

    // Display final account information
    cout << "\nFinal Account Information:";
    myAccount.display();

    

    return 0;
}