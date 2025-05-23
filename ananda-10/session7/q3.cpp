#include <iostream>
#include <string>
using namespace std;

char findExtraChar(const string& s1, const string& s2) {
    int charSum = 0;

    for (char c : s2) {
        charSum += c;
    }

    for (char c : s1) {
        charSum -= c;
    }

    return (char)charSum;
}

int main() {
    string s1, s2;

    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    char extra = findExtraChar(s1, s2);
    cout << "Extra Character: " << extra << endl;

    return 0;
}

