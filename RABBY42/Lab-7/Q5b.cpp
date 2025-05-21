#include <iostream>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int freq[256] = {0};
    for (char c : s1) freq[c]++;
    for (char c : s2) if (--freq[c] < 0) return false;
    return true;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not anagrams");
    return 0;
}
