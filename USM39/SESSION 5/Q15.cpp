#include <iostream>

void checkPointer(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "Pointer is nullptr" << std::endl;
    } else {
        std::cout << "Value: " << *ptr << std::endl;
    }
}

int main() {
    int a = 10;
    int* ptr = &a;
    checkPointer(ptr);
    
    ptr = nullptr;
    checkPointer(ptr);

    return 0;
}
