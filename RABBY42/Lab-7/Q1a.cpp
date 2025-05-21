#include <iostream>
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
    cout << (isPalindrome(s) ? "Palindrome" : "Not a palindrome");
    return 0;
}
