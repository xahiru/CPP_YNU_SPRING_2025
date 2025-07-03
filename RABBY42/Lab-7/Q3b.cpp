#include <iostream>
using namespace std;

char findExtra(string s1, string s2) {
    int freq[256] = {0};
    for (char c : s2) freq[c]++;
    for (char c : s1) freq[c]--;
    for (int i = 0; i < 256; ++i)
        if (freq[i]) return i;
    return 0;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Extra Character: " << findExtra(s1, s2);
    return 0;
}
