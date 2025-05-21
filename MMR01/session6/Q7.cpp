#include <iostream>
#include <string>
using namespace std;

int findPattern(const string &s, const string &p) {
    if (p.empty()) return 0;
    int s_len = s.length();
    int p_len = p.length();
    if (p_len > s_len) return -1;
    
    for (int i = 0; i <= s_len - p_len; ++i) {
        bool match = true;
        for (int j = 0; j < p_len; ++j) {
            if (s[i + j] != p[j]) {
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
    cout << findPattern("Hello", "llo") << endl;       
    cout << findPattern("World", "Doodle") << endl;    
    return 0;
}