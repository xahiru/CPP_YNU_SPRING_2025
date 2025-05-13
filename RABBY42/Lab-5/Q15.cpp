#include <iostream>
using namespace std;

void printValue(int* ptr) {
    if (ptr) cout << "Value: " << *ptr << endl;
    else cout << "Pointer is nullptr" << endl;
}

int main() {
    int x = 10;
    int* ptr1 = nullptr;
    int* ptr2 = &x;
    printValue(ptr1);
    printValue(ptr2);
    return 0;
}