#include <iostream>
using namespace std;

// Function to check and print value if pointer is not nullptr
void printPointerValue(int* ptr) {
    if (ptr == nullptr) {
        cout << "Pointer is nullptr" << endl;
    } else {
        cout << "Value: " << *ptr << endl;
    }
}

int main() {
    int a = 10;
    int* ptr = &a;  // Pointer to a valid integer

    // Call function with a valid pointer
    printPointerValue(ptr);

    ptr = nullptr;  // Set pointer to nullptr

    // Call function with a nullptr
    printPointerValue(ptr);

    return 0;
}
