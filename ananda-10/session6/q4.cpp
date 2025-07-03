#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    int word_count = 1; 

    for (char c : s) {
        if (c == ' ') {
            word_count++;
        }
    }

    cout << "Word count: " << word_count << endl;

    return 0;
}

