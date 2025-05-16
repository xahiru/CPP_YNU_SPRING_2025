#include <iostream>

void printValueIfNotNull(int* ptr) {
    // Check if the pointer is not nullptr
    if (ptr != nullptr) {
        std::cout << "Value: " << *ptr << std::endl; // Dereference and print the value
    } else {
        std::cout << "Pointer is nullptr" << std::endl; // Print if the pointer is nullptr
    }
}

// Main function to test printValueIfNotNull
int main() {
    int value = 10;
    int* ptrToValue = &value;
    int* nullPtr = nullptr;

    printValueIfNotNull(ptrToValue); // Should print "Value: 10"
    printValueIfNotNull(nullPtr);     // Should print "Pointer is nullptr"

    return 0;
}