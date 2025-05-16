#include <iostream>
#include <string>
using namespace std;

int countWords(const string &s) {
    if (s.empty()) return 0;
    int wordCount = 1;
    for (char c : s) {
        if (c == ' ') {
            wordCount++;
        }
    }
    return wordCount;
}

int main() {
    // Test cases
    cout << countWords("Yunnan") << endl;         
    cout << countWords("World is hello") << endl;
    return 0;
}