#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a sentence: ";
    cin.ignore();
    getline(cin, str);

    unordered_set<char> letters;
    for (char c : str) {
        if (isalpha(c)) {
            letters.insert(tolower(c));
        }
    }

    if (letters.size() == 26)
        cout << "Pangram" << endl;
    else
        cout << "Not a Pangram" << endl;

    return 0;
}
