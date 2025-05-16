#include <iostream>
using namespace std;

void findPatternOccurrences(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    for (int i = 0; i <= textLength - patternLength; ++i) {
        int j;
        for (j = 0; j < patternLength; ++j) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found
            }
        }
        if (j == patternLength) {
            cout << "Pattern found at " << i << endl; // Found the pattern
        }
    }
}

int main() {
    string text = "heisahe";
    string pattern = "he";
    findPatternOccurrences(text, pattern);

    text = "abababab";
    pattern = "ab";
    findPatternOccurrences(text, pattern);

    return 0;
}
