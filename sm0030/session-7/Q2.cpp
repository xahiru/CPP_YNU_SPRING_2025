#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    for (size_t i = 0; i <= text.length() - pattern.length(); i++) {
        if (text.substr(i, pattern.length()) == pattern)
            cout << "Pattern found at " << i << endl;
    }

    return 0;
}
