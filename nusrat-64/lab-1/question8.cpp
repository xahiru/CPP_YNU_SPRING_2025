#include <iostream>

int main() {
    int a, b, c;

    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;

    if (a >= b && a >= c) {
        std::cout << "The largest number is: " << a << std::endl;
    } else if (b >= a && b >= c) {
        std::cout << "The largest number is: " << b << std::endl;
    } else {
        std::cout << "The largest number is: " << c << std::endl;
    }

    return 0;
}