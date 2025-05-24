#include <iostream>
#include <string>
using namespace std;

string sliceString(string s) {
    return s.substr(1, s.length() - 2);
}

int main() {
    string s;
    cin >> s;
    cout << sliceString(s) << endl;
    return 0;
}