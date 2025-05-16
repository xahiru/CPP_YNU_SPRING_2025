#include <iostream>
#include <string>
using namespace std;

void findPatternOccurrences(const string &text, const string &pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    
    // Loop through the text to find all occurrences of the pattern
    for (int i = 0; i <= textLength - patternLength; ++i) {
        if (text.substr(i, patternLength) == pattern) {
            cout << "Pattern found at " << i << endl;
        }
    }
}

int main() {
    string text, pattern;

    // Get the text and pattern from the user
    cout << "Enter the text: ";
    getline(cin, text);
    
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // Find and print all occurrences of the pattern in the text
    findPatternOccurrences(text, pattern);

    return 0;
}
