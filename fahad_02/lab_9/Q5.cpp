#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& accNum, double initialBalance) 
        : accountNumber(accNum), balance(initialBalance > 0 ? initialBalance : 0) {
        if (initialBalance < 0) {
            std::cout << "Initial balance cannot be negative. Set to 0." << std::endl;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " successfully." << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                std::cout << "Withdrew $" << amount << " successfully." << std::endl;
            } else {
                std::cout << "Insufficient funds." << std::endl;
            }
        } else {
            std::cout << "Invalid withdrawal amount." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
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

    std::cout << "Enter initial balance: $";
    std::cin >> initialBalance;

    BankAccount account(accNum, initialBalance);

    int choice;
    double amount;

    do {
        std::cout << "\n1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Check Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: $";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter amount to withdraw: $";
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