#include <iostream>
#include <string>
using namespace std;

int findFirstOccurrence(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
    
        for (int j = 0; j < m; j++) {
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

   
    cout << "Enter text: ";
    getline(cin, txt);
    cout << "Enter pattern: ";
    getline(cin, pat);

    
    int result = findFirstOccurrence(txt, pat);
    cout << "First occurrence index: " << result << endl;

    return 0;
}

