#include <iostream>
using namespace std;

void findPattern(string text, string pattern) {
    for (int i = 0; i <= text.length() - pattern.length(); ++i) {
        if (text.substr(i, pattern.length()) == pattern)
            cout << "Pattern found at " << i << endl;
    }
}

int main() {
    string text = "abababab", pattern = "ab";
    findPattern(text, pattern);
    return 0;
}
