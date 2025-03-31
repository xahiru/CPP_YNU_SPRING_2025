#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "Enter 'a' for addition, 's' for subtraction, 'm' for multiplication, 'd' for division: ";
    std::cin >> operation;

    switch (operation) {
        case 'a':
            std::cout << "Result: " << (num1 + num2) << std::endl;
            break;
        case 's':
            std::cout << "Result: " << (num1 - num2) << std::endl;
            break;
        case 'm':
            std::cout << "Result: " << (num1 * num2) << std::endl;
            break;
        case 'd':
            if (num2 != 0) {
                std::cout << "Result: " << (num1 / num2) << std::endl;
            } else {
                std::cout << "Error! Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation entered!" << std::endl;
    }

    return 0;
}