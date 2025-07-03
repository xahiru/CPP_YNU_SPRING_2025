#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt = "YunnanUniversity", pat = "nan";
    int index = -1;
    for (int i = 0; i <= txt.length() - pat.length(); i++) {
        if (txt.substr(i, pat.length()) == pat) {
            index = i;
            break;
        }
    }
    cout << index << endl;
    return 0;
}
