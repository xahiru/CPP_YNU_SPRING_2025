#include <iostream>
using namespace std;

int firstOccurrence(const string& txt, const string& pat) {
    int txtLength = txt.length();
    int patLength = pat.length();

    for (int i = 0; i <= txtLength - patLength; ++i) {
        int j;
        for (j = 0; j < patLength; ++j) {
            if (txt[i + j] != pat[j]) {
                break; // Mismatch found
            }
        }
        if (j == patLength) {
            return i; // Found the pattern
        }
    }
    return -1; // Pattern not found
}

int main() {
    string txt = "YunnanUniversity", pat = "Fr";
    cout << firstOccurrence(txt, pat) << endl; // Output: -1

    txt = "YunnanUniversity", pat = "nan";
    cout << firstOccurrence(txt, pat) << endl; // Output: 3

    txt = "YunnanUniversity", pat = "gr";
    cout << firstOccurrence(txt, pat) << endl; // Output: -1

    return 0;
}