#include <iostream>
using namespace std;

int countWords(const string& s) {
    int count = 0;
    bool inWord = false;

    for (char c : s) {
        if (c == ' ') {
            inWord = false; // We are now outside a word
        } else {
            if (!inWord) {
                count++; // Found a new word
                inWord = true; // We are now inside a word
            }
        }
    }
    return count;
}

int main() {
    string s = "World is hello";
    cout << countWords(s) << endl; // Output: 3

    s = "Yunnan";
    cout << countWords(s) << endl; // Output: 1

    return 0;
}