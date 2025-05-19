#include <iostream>
#include <string>
using namespace std;

void findPattern(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) {
            cout << "Pattern found at " << i << endl;
        }
    }
}

int main() {
    findPattern("heisahe", "he");
    return 0;
}