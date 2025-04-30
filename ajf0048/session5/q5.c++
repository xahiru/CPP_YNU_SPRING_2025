#include <iostream>
using namespace std;

bool verifyLetters(const char* str1, const char* str2) {
    for (int i = 0; str2[i] != '\0'; ++i) {
        bool found = false;
        for (int j = 0; str1[j] != '\0'; ++j) {
            if (str2[i] == str1[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    const char* str1 = "hello";
    const char* str2 = "he";
    cout << (verifyLetters(str1, str2) ? "True" : "False") << endl;
    return 0;
}