#include <iostream>

int main() {
    int num, factorial = 1;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial of a negative number is not defined." << std::endl;
    } else {
        for (int i = 1; i <= num; i++) {
            factorial *= i;  
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}