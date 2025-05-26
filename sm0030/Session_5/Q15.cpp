#include <iostream>

void printPointerValue(int* ptr) {
    if (ptr == nullptr) { // Check if the pointer is nullptr
        std::cout << "Pointer is nullptr" << std::endl;
    } else {
        std::cout << "Value: " << *ptr << std::endl; // Dereference and print the value
    }
}

int main() {
    int* null_ptr = nullptr; // Create a null pointer
    printPointerValue(null_ptr); // Call the function with a null pointer

    int value = 10;
    int* valid_ptr = &value; // Create a valid pointer
    printPointerValue(valid_ptr); // Call the function with a valid pointer

    return 0;
}
