#include <iostream>
using namespace std;

int main() {
    int num, original, reversed = 0;
    
    cout << "Enter a number: ";
    cin >> num;
    original = num;
    
    //handle negative numbers
    if (num < 0) {
        cout << num << " is not a palindrome number." << endl;
        return 0;
    }
    
    //reverse the number
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    //check palindrome
    if (original == reversed) {
        cout << original << " is a palindrome number." << endl;
    } else {
        cout << original << " is not a palindrome number." << endl;
    }
    
    return 0;
}