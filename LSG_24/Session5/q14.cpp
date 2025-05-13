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
    int x = 10;
    int* ptr2 = &x;
    
    printIfValid(ptr1);
    printIfValid(ptr2);
    
    return 0;
}