#include <iostream>
#include <unordered_map>
using namespace std;

char findExtraChar(string s1, string s2) {
    unordered_map<char, int> freq;
    for (char c : s1) freq[c]++;
    for (char c : s2) {
        if (--freq[c] < 0) return c;
    }
    return '\0';
}

int main() {
    cout << "Extra Character: " << findExtraChar("abcd", "abecd");
    return 0;
}