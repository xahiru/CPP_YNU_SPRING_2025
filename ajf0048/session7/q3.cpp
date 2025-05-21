#include <iostream>
using namespace std;

char findExtraCharacter(const string& s1, const string& s2) {
    int charCount[256] = {0}; // Assuming ASCII characters

    for (char c : s1) {
        charCount[c]++;
    }

    for (char c : s2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return c; // Found the extra character
        }
    }
    return '\0'; // Should not reach here
}

int main() {
    string s1 = "abcd";
    string s2 = "abecd";
    cout << "Extra Character: " << findExtraCharacter(s1, s2) << endl;

    return 0;
}
