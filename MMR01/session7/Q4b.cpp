#include <iostream>
#include <bitset>
#include <cctype>
using namespace std;

bool isPangram(string s) {
    bitset<26> letters;
    for (char c : s) {
        if (isalpha(c)) {
            letters.set(tolower(c) - 'a');
        }
    }
    return letters.all();
}

int main() {
    cout << (isPangram("Hello World") ? "Pangram" : "Not a pangram");
    return 0;
}