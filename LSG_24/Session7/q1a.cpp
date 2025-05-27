#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    string s;
    cin >> s;
    cout << (isPalindrome(s) ? "Palindrome" : "Not a palindrome") << endl;
    return 0;
}