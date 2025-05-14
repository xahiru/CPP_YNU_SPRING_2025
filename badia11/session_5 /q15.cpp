#include <iostream>
using namespace std;

void printIfValid(int* ptr) {
    if (ptr == nullptr) {
        cout << "Pointer is nullptr" << endl;
    } else {
        cout << "Value: " << *ptr << endl;
    }
}

int main() {
    int* ptr1 = nullptr;
    int value = 10;
    int* ptr2 = &value;

    // Test with null pointer
    printIfValid(ptr1);

    // Test with valid pointer
    printIfValid(ptr2);

    return 0;
}
