#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& accNum, double initialBalance = 0.0)
        : accountNumber(accNum), balance(initialBalance >= 0 ? initialBalance : 0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cerr << "Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cerr << "Withdrawal amount must be positive." << std::endl;
        } else if (amount > balance) {
            std::cerr << "Insufficient balance." << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrew: $" << amount << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << std::endl;
    }
};

int main() {
    std::string accNum;
    double initialBalance;

    std::cout << "Enter account number: ";
    std::getline(std::cin, accNum);

    std::cout << "Enter initial balance: $";
    std::cin >> initialBalance;

    BankAccount account(accNum, initialBalance);
    account.display();

    double amount;

    std::cout << "\nEnter amount to deposit: $";
    std::cin >> amount;
    account.deposit(amount);

    std::cout << "Enter amount to withdraw: $";
    std::cin >> amount;
    account.withdraw(amount);

    account.display();

    return 0;
}
