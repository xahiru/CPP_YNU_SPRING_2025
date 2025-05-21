#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    // Input a string with multiple words
    cout << "Enter a string with multiple words: ";
    getline(cin, s); // This reads the entire line, including spaces

    // Output the string
    cout << "You entered: " << s << endl;

    return 0;
}
