#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countWords(const string& s) {
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

int main() {
    string s = "World is hello";
    cout << countWords(s) << endl; // Output: 3
    return 0;
}
