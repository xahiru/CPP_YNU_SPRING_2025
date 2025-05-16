#include <iostream>
#include <cctype>
#include <set>
using namespace std;

bool isPangram(string str) {
    set<char> letters;
    for(char c : str) {
        if(isalpha(c)) letters.insert(tolower(c));
    }
    return letters.size() == 26;
}

int main() {
    string str = "The quick brown fox jumps over the lazy dog";
    cout << (isPangram(str) ? "Pangram" : "Not a Pangram");
    return 0;
}