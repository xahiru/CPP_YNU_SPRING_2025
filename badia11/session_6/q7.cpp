#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    string p = "llo";
    int index = -1;

    for (int i = 0; i <= s.length() - p.length(); i++) {
        if (s.substr(i, p.length()) == p) {
            index = i;
            break;
        }
    }

    cout << index << endl;
    return 0;
}
