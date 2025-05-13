#include <iostream>
#include <unordered_set>
using namespace std;

bool verify(string s1, string s2) {
    unordered_set<char> chars(s1.begin(), s1.end());
    for (char c : s2) {
        if (chars.find(c) == chars.end()) return false;
    }
    return true;
}

int main() {
    string s1 = "hello", s2 = "he";
    cout << verify(s1, s2);
    return 0;
}