#include <iostream>

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " is an Even Number." << std::endl;
    } else {
        std::cout << num << " is an Odd Number." << std::endl;
    }

    return 0;
}