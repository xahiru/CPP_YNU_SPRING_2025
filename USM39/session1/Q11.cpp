#include <iostream>
using namespace std;

int main() {
    int num, reversed = 0, original;
    cout << "Enter a number: ";
    cin >> num;
    original = num;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    if (original == reversed)
        cout << original << " is a Palindrome understand." << endl;
    else
        cout << original << " is not a Palindrome understand." << endl;
    return 0;
}