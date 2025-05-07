#include <iostream>

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 3;
    int num2 = 5;

    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swapNumbers(num1, num2);

    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
