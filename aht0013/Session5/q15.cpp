#include <iostream>
using namespace std;

void printIfNotNull(const int* ptr) {
    if (ptr != nullptr) {
        cout << "Value: " << *ptr << endl;
    } else {
        cout << "Pointer is nullptr" << endl;
    }
}

int main() {
    int* ptr1 = nullptr;
    int value = 10;
    int* ptr2 = &value;

    printIfNotNull(ptr1);
    printIfNotNull(ptr2);

    return 0;
}