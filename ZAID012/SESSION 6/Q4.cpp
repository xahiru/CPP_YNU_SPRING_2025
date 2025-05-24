#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    
 
    getline(cin, s);
    
    int wordCount = 1;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            wordCount++;
        }
    }
    
    cout << "Word count: " << wordCount << endl;
    
    return 0;
}
