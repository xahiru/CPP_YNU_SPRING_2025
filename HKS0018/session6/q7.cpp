#include <iostream>
#include <string>

using namespace std;

int findPattern(const string &s, const string &p) {
    if (p.empty()) 
    return 0; 
    if (s.length() < p.length()) 
    return -1;
    
    for (int i = 0; i <= s.length() - p.length(); ++i) {
        bool match = true;
        for (int j = 0; j < p.length(); ++j) {
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
    string s, p;
    getline(cin, s);
    getline(cin, p); 
    
    int index = findPattern(s, p);
    cout << index << endl;
    
    return 0;
}