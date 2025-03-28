#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";  //Ask for enter character
    cin >> ch;

   
    cout << "ASCII value of '" << ch << "' is: " << int(ch) << endl;  // Print the ASCII value using type casting (int)

    return 0;
}