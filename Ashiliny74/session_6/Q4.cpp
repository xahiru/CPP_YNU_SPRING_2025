#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int countWords(string s) {
    stringstream ss(s);
    string word;
    int count = 0;
    
    while (ss >> word) {
        count++;
    }
    
    return count;
}

int main() {
    string s;
    getline(cin, s);
    cout << countWords(s) << endl;
    return 0;
}