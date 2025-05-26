#include <iostream>
#include <string>
using namespace std;

int stringLength(const string &s) {
    return s.length();
}

int main() {
    string s;
    cin >> s;
    cout << stringLength(s) << endl;
    return 0;
}