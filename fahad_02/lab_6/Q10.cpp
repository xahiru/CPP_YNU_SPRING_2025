#include <iostream>
using namespace std;

int firstOccurrence(const string &txt, const string &pat) {
    int n = txt.size();
    int m = pat.size();

    // Loop through the string txt and check for matching substring of length m
    for (int i = 0; i <= n - m; ++i) {
        bool found = true;
        // Compare substring starting at index i in txt with pat
        for (int j = 0; j < m; ++j) {
            if (txt[i + j] != pat[j]) {
                found = false;
                break;
            }
        }

        // If the substring matches, return the starting index
        if (found) {
            return i;
        }
    }

    // If no match is found, return -1
    return -1;
}

int main() {
    string txt, pat;

    // Input the text and pattern strings
    cout << "Enter the text string: ";
    getline(cin, txt);

    cout << "Enter the pattern string: ";
    getline(cin, pat);

    // Call function to find first occurrence
    int result = firstOccurrence(txt, pat);

    // Output the result
    cout << "First occurrence index: " << result << endl;

    return 0;
}
