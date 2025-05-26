#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    
    int txt_len = txt.size();
    int pat_len = pat.size();
    
    if (pat_len > txt_len) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 0; i <= txt_len - pat_len; ++i) {
        bool match = true;
        for (int j = 0; j < pat_len; ++j) {
            if (txt[i + j] != pat[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}