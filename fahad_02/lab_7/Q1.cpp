#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;  // Not a palindrome if mismatch occurs
        }
        left++;
        right--;
    }
    return true;  // The string is a palindrome
}

int main() {
    string input;

    // Get input string from the user
    cout << "Enter a string: ";
    getline(cin, input);

    // Check if the input string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
