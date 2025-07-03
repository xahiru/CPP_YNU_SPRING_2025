#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool areAnagrams(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;
    unordered_map<char, int> freq;
    for (char c : s1) freq[c]++;
    for (char c : s2) {
        if (--freq[c] < 0) return false;
    }
    return true;
}

int main() {
    string s1 = "abc";
    string s2 = "abd";
    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not Anagrams") << endl;
    return 0;
}



