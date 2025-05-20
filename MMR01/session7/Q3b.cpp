#include <iostream>
using namespace std;

char findExtraChar(string s1, string s2) {
    char res = 0;
    for (char c : s1) res ^= c;
    for (char c : s2) res ^= c;
    return res;
}

int main() {
    cout << "Extra Character: " << findExtraChar("abcd", "abfcd");
    return 0;
}