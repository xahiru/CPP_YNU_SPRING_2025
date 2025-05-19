#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

int main() {
    string s = "abcba";
    cout << (isPalindrome(s) ? "Palindrome" : "Not a palindrome");
    return 0;
}