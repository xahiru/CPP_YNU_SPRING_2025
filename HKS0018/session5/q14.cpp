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
    int* nullPtr = nullptr;
    int num = 10;
    int* validPtr = &num;
    
    printValue(nullPtr); 
    printValue(validPtr);  

    return 0;
}
