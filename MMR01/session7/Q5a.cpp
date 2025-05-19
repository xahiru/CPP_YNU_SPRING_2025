#include <algorithm>
#include <iostream>
using namespace std;

bool areAnagrams(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    cout << (areAnagrams("listen", "silent") ? "Anagrams" : "Not anagrams");
    return 0;
}