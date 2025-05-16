#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str = "abcba", rev = str;
    reverse(rev.begin(), rev.end());
    cout << (str == rev ? "Palindrome" : "Not a palindrome");
    return 0;
}