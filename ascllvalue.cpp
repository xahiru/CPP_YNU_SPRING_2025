#include <iostream>
using namespace std;

int main() {
    char ch;
    
    // Input character from user
    cout << "Enter a character: ";
    cin >> ch;
    
    // Print ASCII value
    cout << "ASCII Value of '" << ch << "' = " << int(ch) << endl;
    
    return 0;
}