#include <iostream>
#include <string>
using namespace std;

int countWords(const string &s) {
    int count = 1;
    for (char c : s) {
        if (c == ' ') {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    getline(cin, s);
    cout << countWords(s) << endl;
    return 0;
}