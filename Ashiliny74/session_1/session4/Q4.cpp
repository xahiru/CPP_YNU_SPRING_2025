#include <iostream>

void swap(int *a, int *b) {
    // Swap the values using a temporary variable
    int temp = *a; // Dereference pointer a to get its value
    *a = *b;       // Assign the value of b to a
    *b = temp;     // Assign the value of temp (original a) to b
}

int main() {
    int a = 3; // Example input
    int b = 5; // Example input

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    // Call the swap function with the addresses of a and b
    swap(&a, &b);

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl; // Output: 5 3

    return 0;
}