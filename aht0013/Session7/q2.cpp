#include <iostream>
using namespace std;

void findPattern(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    for(int i = 0; i <= n - m; ++i) {
        if(text.substr(i, m) == pattern)
            cout << "Pattern found at " << i << endl;
    }
}

int main() {
    string text = "abababab", pattern = "ab";
    findPattern(text, pattern);
    return 0;
}