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
    int a = 10;
    int* p1 = nullptr;
    int* p2 = &a;

    printValue(p1);
    printValue(p2);

    return 0;
}
