#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello", p = "llo";
    int pos = -1;
    for (int i = 0; i <= s.length() - p.length(); i++) {
        if (s.substr(i, p.length()) == p) {
            pos = i;
            break;
        }
    }
    cout << pos << endl;
    return 0;
}
