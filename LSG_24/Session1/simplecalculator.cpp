#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    return original == reversed;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if (isPalindrome(number))
        cout << number << " is a palindrome number.";
    else
        cout << number << " is not a palindrome number.";
    
    return 0;
}