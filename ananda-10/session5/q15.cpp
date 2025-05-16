#include <iostream>
using namespace std;

void printIfNotNull(int* ptr) {
    if (ptr == nullptr) {
        cout << "Pointer is nullptr" << endl;
    } else {
        cout << "Value: " << *ptr << endl;
    }
}

int main() {
    int* p1 = nullptr;
    int value = 10;
    int* p2 = &value;

    printIfNotNull(p1);  
    printIfNotNull(p2);  

    return 0;
}
q15
