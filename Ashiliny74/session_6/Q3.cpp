#include <iostream>
#include <string>
using namespace std;

int lengthOfString(string s) {
    return s.length();
}

int main() {
    string s;
    getline(cin, s);
    cout << lengthOfString(s) << endl;
    return 0;
}