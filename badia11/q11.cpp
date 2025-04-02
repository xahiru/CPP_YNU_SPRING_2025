#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0, remainder, original;
    cout << "Number to Check = ";
    cin >> number;
    original = number;

    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    if (original == reversed)
        cout << original << " is a palindrome number." << endl;
    else
        cout << original << " is not a palindrome number." << endl;
    return 0;
}