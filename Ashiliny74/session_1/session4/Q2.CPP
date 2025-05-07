#include <iostream>

void updateVar(int *a) {
    // Increment the value pointed to by the pointer 'a' by 10
    *a += 10;
}

int main() {
    int a = 4; // Example 1
    updateVar(&a); // Pass the address of 'a'
    std::cout << a << std::endl; // Output: 14

    a = 61; // Example 2
    updateVar(&a); // Pass the address of 'a'
    std::cout << a << std::endl; // Output: 71

    return 0;
}