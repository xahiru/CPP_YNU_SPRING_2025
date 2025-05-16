#include <iostream>
#include <string>
using namespace std;

void findPattern(const string& text, const string& pattern) {
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        cout << "Pattern found at " << pos << endl;
        pos = text.find(pattern, pos + 1);
    }
}

int main() {
    string text = "abababab";
    string pattern = "ab";
    findPattern(text, pattern);
    return 0;
}