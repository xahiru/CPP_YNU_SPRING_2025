#include <iostream>
using namespace std;

char findExtraChar(string s1, string s2) {
    char extra = 0;
    for (char c : s1) extra ^= c;
    for (char c : s2) extra ^= c;
    return extra;
}

int main() {
    string s1 = "abcd", s2 = "abecd";
    cout << "Extra Character: " << findExtraChar(s1, s2);
    return 0;
}
