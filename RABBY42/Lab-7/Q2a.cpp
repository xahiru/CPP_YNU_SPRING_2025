#include <iostream>
using namespace std;

void findPattern(string text, string pat) {
    int n = text.length(), m = pat.length();
    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pat[j]) break;
        }
        if (j == m) cout << "Pattern found at " << i << endl;
    }
}

int main() {
    string text, pat;
    cin >> text >> pat;
    findPattern(text, pat);
    return 0;
}