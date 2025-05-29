#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount!" << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        }
    }
    void displayAccountInfo() const {
        std::cout << "\nAccount Number: " << accountNumber << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};

int main() {
    std::string accNum;
    double initialBalance;

    std::cout << "Enter account number: ";
    std::getline(std::cin, accNum);
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    BankAccount account(accNum, initialBalance);

    int choice;
    double amount;
    do {
        std::cout << "\n--- Bank Account Menu ---\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Display Info\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayAccountInfo();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }

    } while(choice != 4);

    return 0;
}

