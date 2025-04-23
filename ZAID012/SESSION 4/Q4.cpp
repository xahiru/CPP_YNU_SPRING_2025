#include <iostream>

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b;       
    *b = temp;     
}

int main() {
    int a = 3, b = 5;

    std::cout << "Input: a = " << a << ", b = " << b << std::endl;
    swap(&a, &b); 
    std::cout << "Output: " << a << " " << b << std::endl; 

    return 0;
}