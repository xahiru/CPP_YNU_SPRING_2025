#include <iostream>
#include <string>
using namespace std;

char findExtraChar(const string &s1, const string &s2) {
    char res = 0;
    for (char c : s1) res ^= c;
    for (char c : s2) res ^= c;
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Extra Character: " << findExtraChar(s1, s2) << endl;
    return 0;
}