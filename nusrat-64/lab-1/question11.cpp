#include <iostream>

int main() {
    int num, originalNum, reversedNum = 0, digit;

    std::cout << "Enter a number: ";
    std::cin >> num;

    originalNum = num; 
    
    while (num > 0) {
        digit = num % 10;               
        reversedNum = reversedNum * 10 + digit;
        num /= 10;                      
    }

    if (originalNum == reversedNum) {
        std::cout << originalNum << " is a palindrome number." << std::endl;
    } else {
        std::cout << originalNum << " is not a palindrome number." << std::endl;
    }

    return 0;
}