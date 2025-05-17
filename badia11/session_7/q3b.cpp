#include <iostream>
#include <string>
using namespace std;

char findExtraChar(string s1, string s2) {
    char result = 0;
    for (char c : s1)
        result ^= c;
    for (char c : s2)
        result ^= c;
    return result;
}

int main() {
    string s1 = "abcd", s2 = "abecd";
    cout << "Extra Character: " << findExtraChar(s1, s2) << endl;
    return 0;
}
