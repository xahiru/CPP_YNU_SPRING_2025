#include <iostream>
#include <sstream>
using namespace std;

int countWords(const string &s) {
    int wordCount = 0;
    stringstream ss(s);
    string word;

    // Read each word from the stringstream and count
    while (ss >> word) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    string s;

    // Input the string
    cout << "Enter a string: ";
    getline(cin, s);

    // Output the word count
    cout << "Number of words: " << countWords(s) << endl;

    return 0;
}
