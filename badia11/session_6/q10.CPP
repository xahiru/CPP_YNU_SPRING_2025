#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt = "YunnanUniversity";
    string pat = "nan";
    int pos = -1;

    for (int i = 0; i <= txt.length() - pat.length(); i++) {
        bool match = true;
        for (int j = 0; j < pat.length(); j++) {
            if (txt[i + j] != pat[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            pos = i;
            break;
        }
    }

    cout << pos << endl;
    return 0;
}
