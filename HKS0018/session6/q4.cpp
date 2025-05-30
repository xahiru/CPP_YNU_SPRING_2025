#include <iostream>
#include <string>

using namespace std;

int countWords(const string &s) {
    if (s.empty())  
    return 0;  
    
    int wordCount = 1;        
    for (char c : s) {
        if (c == ' ') {
            wordCount++;
        }
    }
    return wordCount;
}

int main() {
    string s;
    getline(cin, s);  
    cout << countWords(s) << endl;

    return 0;
}