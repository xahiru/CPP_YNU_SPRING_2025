#include <iostream>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 3;
    int b = 5;
    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;
    return 0;
}