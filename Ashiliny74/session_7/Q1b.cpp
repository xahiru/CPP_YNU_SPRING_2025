#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

int main() {
    string s = "abcba";
    cout << (isPalindrome(s) ? "Palindrome" : "Not a palindrome") << endl;
    return 0;
}