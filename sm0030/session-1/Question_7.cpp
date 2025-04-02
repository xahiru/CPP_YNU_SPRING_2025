#include <iostream>

int main() {
    int number = 28;

    if (number % 2 == 0) {
        std::cout << number << " is Even Number." << std::endl;
    } else {
        std::cout << number << " is Odd Number." << std::endl;
    }

    return 0;
}