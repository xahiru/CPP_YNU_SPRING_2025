#include <iostream>
#include <string>

using namespace std;

void findPattern(const string &text, const string &pattern) {
    int textLen = text.size();
    int patLen = pattern.size();
    for (int i = 0; i <= textLen - patLen; i++) {
        bool match = true;
        for (int j = 0; j < patLen; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << "Pattern found at " << i << endl;
        }
    }
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    findPattern(text, pattern);

    
    return 0;
}