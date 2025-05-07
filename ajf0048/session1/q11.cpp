#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num) {
    string s = to_string(num);
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

int main() {
    int number;
    cout << "Number to Check = ";
    cin >> number;
    if (isPalindrome(number))
        cout << number << " is a palindrome number." << endl;
    else
        cout << number << " is not a palindrome number." << endl;
    return 0;
}