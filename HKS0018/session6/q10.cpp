#include <iostream>
#include <string>

using namespace std;

int findFirstOccurrence(const string &txt, const string &pat) {
    int txtLen = txt.size();
    int patLen = pat.size();
    
    if (patLen == 0) {

        return 0;
    }
    
    for (int i = 0; i <= txtLen - patLen; ++i) {
        bool match = true;
        for (int j = 0; j < patLen; ++j) {
            if (txt[i + j] != pat[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }

    return -1;
}

int main() {
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    
    int result = findFirstOccurrence(txt, pat);
    cout << result << endl;
    
    
    return 0;
}