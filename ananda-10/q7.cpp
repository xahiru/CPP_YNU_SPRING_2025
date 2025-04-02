#include <iostream>

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << number << " is " << (number % 2 == 0 ? "Even" : "Odd") << " Number" << std::endl;

    return 0;
}
