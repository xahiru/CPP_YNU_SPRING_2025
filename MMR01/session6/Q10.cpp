#include <iostream>
#include <string>
using namespace std;

int findFirstOccurrence(const string &txt, const string &pat) {
    if (pat.empty()) return 0;
    int txt_len = txt.length();
    int pat_len = pat.length();
    if (pat_len > txt_len) return -1;
    
    for (int i = 0; i <= txt_len - pat_len; ++i) {
        bool match = true;
        for (int j = 0; j < pat_len; ++j) {
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
    // Test cases
    cout << findFirstOccurrence("YunnanUniversity", "Fr") << endl;       
    cout << findFirstOccurrence("YunnanUniversity", "nan") << endl;     
    cout << findFirstOccurrence("YunnanUniversity", "gr") << endl;      
    return 0;
}