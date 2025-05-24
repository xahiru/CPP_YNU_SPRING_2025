#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor to initialize account
    BankAccount(const std::string& accNum = "", double initialBalance = 0.0) {
        accountNumber = accNum;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            std::cout << "Warning: Initial balance cannot be negative. Set to 0." << std::endl;
        }
    }

    // Getter for account number
    std::string getAccountNumber() const {
        return accountNumber;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Deposit money into account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount. Amount must be positive." << std::endl;
        }
    }

    // Withdraw money from account
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                std::cout << "Successfully withdrew $" << amount << std::endl;
            } else {
                std::cout << "Insufficient funds. Cannot withdraw $" << amount << std::endl;
            }
        } else {
            std::cout << "Invalid withdrawal amount. Amount must be positive." << std::endl;
        }
    }

    // Display account information
    void displayAccountInfo() const {
        std::cout << "\nAccount Information:" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    // Create a bank account
    std::string accNum;
    double initialDeposit;

    std::cout << "Enter account number: ";
    std::getline(std::cin, accNum);

    std::cout << "Enter initial deposit amount: $";
    std::cin >> initialDeposit;

    BankAccount account(accNum, initialDeposit);

    // Perform transactions
    int choice;
    double amount;

    do {
        std::cout << "\nBank Account Menu:" << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. View Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter deposit amount: $";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdrawal amount: $";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayAccountInfo();
                break;
            case 4:
                std::cout << "Thank you for banking with us!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}