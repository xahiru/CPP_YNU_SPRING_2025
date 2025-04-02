#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0, original, remainder;
    
    cout << "Enter a number: ";
    cin >> number;
    
    original = number;  
    while (number) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }
    cout << original << (original == reversed ? " is a palindrome." : " is not a palindrome.") << endl;
    
    return 0;
}
