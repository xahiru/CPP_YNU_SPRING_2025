#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "abba";
    cout << (isPalindrome(s) ? "Palindrome" : "Not a palindrome");
    return 0;
}