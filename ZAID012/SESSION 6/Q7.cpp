#include <iostream>
#include <string>
using namespace std;

int findPattern(string s, string p) {
    size_t found = s.find(p);
    if (found != string::npos) {
        return found;
    }
    return -1;
}

int main() {
    string s1 = "Hello";
    string p1 = "llo";
    
    string s2 = "World";
    string p2 = "Doodle";
    
    cout << "Pattern " << p1 << " in " << s1 << ": " << findPattern(s1, p1) << endl;
    cout << "Pattern " << p2 << " in " << s2 << ": " << findPattern(s2, p2) << endl;
    
    return 0;
}