#include <iostream>
#include <string>
using namespace std;

char findExtraChar(const string& s1, const string& s2) {
    int count[256] = {0};
    for (char c : s2) count[c]++;
    for (char c : s1) count[c]--;
    for (int i = 0; i < 256; i++) {
        if (count[i] == 1) return (char)i;
    }
    return '\0';
}

int main() {
    string s1 = "abcd";
    string s2 = "abecd";
    cout << "Extra Character: " << findExtraChar(s1, s2) << endl;
    return 0;
}