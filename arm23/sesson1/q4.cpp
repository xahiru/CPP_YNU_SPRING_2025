#include <iostream>

int main() {
    int a, b;
    
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    // Swapping logic
    int temp = a;
    a = b;
    b = temp;

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;
    
    return 0;
}