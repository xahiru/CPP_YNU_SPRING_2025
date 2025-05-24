#include <iostream>
#include <string>
using namespace std;

bool isPangram(string str) {
    bool letters[26] = {false};
    for (char c : str) {
        if (isalpha(c)) {
            letters[tolower(c) - 'a'] = true;
        }
    }

    for (bool present : letters) {
        if (!present) return false;
    }

    return true;
}

int main() {
    string sentence;
    getline(cin, sentence);

    if (isPangram(sentence))
        cout << "Pangram" << endl;
    else
        cout << "Not a Pangram" << endl;

    return 0;
}
