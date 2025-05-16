#include <iostream>
#include <string>
using namespace std;

int findPattern(const string& s, const string& p) {
    int len_s = s.size();
    int len_p = p.size();
    
    for (int i = 0; i <= len_s - len_p; i++) {
        if (s.substr(i, len_p) == p) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s1 = "Hello";
    string p1 = "llo";
    cout << findPattern(s1, p1) << endl;
    
    string s2 = "World";
    string p2 = "Doodle";
    cout << findPattern(s2, p2) << endl;
    
    return 0;
}
