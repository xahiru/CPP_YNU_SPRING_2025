#include <iostream>
#include <string>
using namespace std;

string getSubstring(const string &s, int L, int R) {
    return s.substr(L, R - L + 1);
}

int main() {
    string s;
    int L, R;
    cin >> s >> L >> R;
    cout << getSubstring(s, L, R) << endl;
    return 0;
}