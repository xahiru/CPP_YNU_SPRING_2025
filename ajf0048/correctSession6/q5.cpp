#include <iostream>
using namespace std;

string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        swap(s[i], s[n - i - 1]); // Swap characters
    }
    return s;
}

int main() {
    string s = "Hello";
    cout << reverseString(s) << endl; // Output: olleH

    s = "World";
    cout << reverseString(s) << endl; // Output: dlroW

    return 0;
}