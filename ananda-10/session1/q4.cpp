#include <iostream>

int main() {
    int a, b;
    
    std::cout << "Enter two numbers (a and b): ";
    std::cin >> a >> b;

    int temp = a;
    a = b;
    b = temp;
    
    std::cout << "After swapping:\n";
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
