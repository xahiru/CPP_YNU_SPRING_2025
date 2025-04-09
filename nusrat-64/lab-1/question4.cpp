#include <iostream>

int main() {
    int a, b, temp;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    // Swapping using a temporary variable
    temp = a;
    a = b;
    b = temp;

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}