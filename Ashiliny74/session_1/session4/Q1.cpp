#include <iostream>

int main() {
    int a = 4; // Example 1
    int* ptr = &a; // Get the address of 'a'
    
    std::cout << *ptr << std::endl; // Dereference the pointer to get the value (Output: 4)

    a = 61; // Example 2
    std::cout << *ptr << std::endl; // Output: 61

    return 0;
}