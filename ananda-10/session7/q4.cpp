#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPangram(const string& s) {
    bool letters[26] = {false};  
    int count = 0;  

    for (char ch : s) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            int index = ch - 'a';
            if (!letters[index]) {
                letters[index] = true;
                count++;
                if (count == 26) {
                    return true;
                }
            }
        }
    }
    return false; 
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (isPangram(input)) {
        cout << "Pangram" << endl;
    } else {
        cout << "Not a Pangram" << endl;
    }

    return 0;
}

