#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) return false;
    int count[256] = {0};
    for (char c : s1) count[c]++;
    for (char c : s2) {
        if (--count[c] < 0) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not Anagrams") << endl;
    return 0;
}