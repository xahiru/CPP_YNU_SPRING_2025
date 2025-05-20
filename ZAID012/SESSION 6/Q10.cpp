#include <iostream>
#include <string>
using namespace std;

int firstOccurrence(string txt, string pat) {
    int txtLen = txt.length();
    int patLen = pat.length();
    
    for (int i = 0; i <= txtLen - patLen; i++) {
        int j;
        for (j = 0; j < patLen; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        
        if (j == patLen) {
            return i;
        }
    }
    
    return -1; // Pattern not found
}

int main() {
    string txt1 = "YunnanUniversity";
    string pat1 = "Fr";
    
    string txt2 = "YunnanUniversity";
    string pat2 = "nan";
    
    string txt3 = "YunnanUniversity";
    string pat3 = "gr";
    
    cout << "First occurrence of " << pat1 << " in " << txt1 << ": " 
         << firstOccurrence(txt1, pat1) << endl;
    
    cout << "First occurrence of " << pat2 << " in " << txt2 << ": " 
         << firstOccurrence(txt2, pat2) << endl;
    
    cout << "First occurrence of " << pat3 << " in " << txt3 << ": " 
         << firstOccurrence(txt3, pat3) << endl;
    
    return 0;
}