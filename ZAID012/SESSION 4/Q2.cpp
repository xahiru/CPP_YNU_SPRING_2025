#include <iostream>
void updateVar(int *ptr) {
    *ptr += 10; 
}

int main() {
    int a;
    a = 4;
    std::cout << "Input: a = " << a << std::endl;
    updateVar(&a); 
    std::cout << "Output: " << a << std::endl;
    a = 61;
    std::cout << "Input: a = " << a << std::endl;
    updateVar(&a); 
    std::cout << "Output: " << a << std::endl;

    return 0;
}