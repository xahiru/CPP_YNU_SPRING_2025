#include <iostream>
#include <string>
using namespace std;

void findPattern(string text, string pattern) {
    int tLen = text.length(), pLen = pattern.length();
    for (int i = 0; i <= tLen - pLen; i++) {
        if (text.substr(i, pLen) == pattern)
            cout << "Pattern found at " << i << endl;
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    findPattern(text, pattern);
    return 0;
}
