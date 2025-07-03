#include <iostream>
#include <string>
using namespace std;

string getSubstring(string s, int L, int R) {
    return s.substr(L, R - L + 1);
}

int main() {
    string s1 = "cdbkdub";
    int L1 = 0, R1 = 5;
    
    string s2 = "sdiblcsdbud";
    int L2 = 3, R2 = 7;
    
    cout << "Substring of " << s1 << " from " << L1 << " to " << R1 << ": " 
         << getSubstring(s1, L1, R1) << endl;
    
    cout << "Substring of " << s2 << " from " << L2 << " to " << R2 << ": " 
         << getSubstring(s2, L2, R2) << endl;
    
    return 0;
}