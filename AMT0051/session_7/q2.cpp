#include <iostream>
#include <string>
using namespace std;

void findPatternOccurrences(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    for (int i = 0; i <= textLength - patternLength; ++i) {
        if (text.substr(i, patternLength) == pattern) {
            cout << "Pattern found at " << i << endl;
        }
    }
}

int main() {
    
    cout << "Example 1:" << endl;
    string text1 = "heisahe";
    string pattern1 = "he";
    findPatternOccurrences(text1, pattern1);

    cout << "\nExample 2:" << endl;
    string text2 = "abababab";
    string pattern2 = "ab";
    findPatternOccurrences(text2, pattern2);

    return 0;
}
