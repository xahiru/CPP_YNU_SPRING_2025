#include <iostream>
using namespace std;

void printIfValid(const int* ptr) {
    if (ptr != nullptr) {
        cout << "Value: " << *ptr << endl;
    } else {
        cout << "Pointer is nullptr" << endl;
    }
}

int main() {
    int value = 10;
    int* validPtr = &value;
    int* nullPtr = nullptr;

    // Test with null pointer
    printIfValid(nullPtr);  // Output: Pointer is nullptr

    // Test with valid pointer
    printIfValid(validPtr); // Output: Value: 10

    return 0;
}