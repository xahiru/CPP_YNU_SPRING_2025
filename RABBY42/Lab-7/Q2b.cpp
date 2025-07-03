#include <iostream>
#include <string>
using namespace std;

void findPattern(string text, string pattern) {
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        cout << "Pattern found at " << pos << endl;
        pos = text.find(pattern, pos + 1);
    }
}


int main() {
    findPattern("abababab", "ab");
    return 0;
}
