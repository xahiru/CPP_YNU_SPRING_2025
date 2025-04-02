#include <iostream>

int main() {
    int year;

    std::cout << "Enter a year: ";
    std::cin >> year;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        std::cout << year << " is a Leap Year." << std::endl;
    } else {
        std::cout << year << " is not a Leap Year." << std::endl;
    }

    return 0;
}
