#include <iostream>

int main() {
    int a;
    a = 4;
    std::cout << "Input: a = " << a << std::endl;
    std::cout << "Output: " << *(&a) << std::endl; 
    a = 61;
    std::cout << "Input: a = " << a << std::endl;
    std::cout << "Output: " << *(&a) << std::endl; 
    return 0;
}
