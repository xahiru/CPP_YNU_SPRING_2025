#include <iostream>
using namespace std;

int main() {
    int number = 1231, reversed = 0, original = number;

    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    if (original == reversed) {
        cout << original << " is a palindrome number." << endl;
    } else {
        cout << original << " is not a palindrome number." << endl;
    }

    return 0;
}