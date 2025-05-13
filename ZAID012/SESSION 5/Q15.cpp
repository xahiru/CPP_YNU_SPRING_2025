#include <iostream>
using namespace std;

void printValue(int* ptr) {
    if (ptr == nullptr) {
        cout << "Pointer is nullptr" << endl;
    } else {
        cout << "Value: " << *ptr << endl;
    }
}

int main() {
    int value = 10;
    int* ptr = &value;
    printValue(ptr);

    ptr = nullptr;
    printValue(ptr);

    return 0;
}