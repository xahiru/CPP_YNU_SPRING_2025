#include <iostream>
using namespace std;

void printAlphabets(char c1, char c2) {
    // Loop through the characters from c1 to c2
    for (char c = c1; c <= c2; ++c) {
        cout << c << " "; // Print each character followed by a space
    }
}

int main() {
    char c1, c2;

    // Input two characters
    cout << "Enter first character: ";
    cin >> c1;
    
    cout << "Enter second character: ";
    cin >> c2;

    // Print alphabets from c1 to c2
    printAlphabets(c1, c2);

    return 0;
}
