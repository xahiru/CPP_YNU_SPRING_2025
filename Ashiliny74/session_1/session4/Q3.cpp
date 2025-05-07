#include <iostream>

void swap(int &a, int &b) {
    // Swap the values using a temporary variable
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 3; // Example input
    int b = 5; // Example input

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    // Call the swap function
    swap(a, b);

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl; // Output: 5 3

    return 0;
}