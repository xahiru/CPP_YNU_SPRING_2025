#include <iostream>
#include <string>

using namespace std;

char findExtraChar(const string &s1, const string &s2) {
    char result = 0;
    for (char c : s1) {
        result ^= c;
    }
    for (char c : s2) {
        result ^= c;
    }

    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    char extra = findExtraChar(s1, s2);
    cout << "Extra Character: " << extra << endl;

    return 0;
}