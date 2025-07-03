#include <iostream>
#include <algorithm>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not anagrams");
    return 0;
}
