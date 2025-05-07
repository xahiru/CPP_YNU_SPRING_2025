#include <iostream>
using namespace std;

int main() {
    const char* str = "A string."; // Define the string
    const char* p = str; // Initialize the pointer to the start of the string

    // Print the letter at index 0, the pointer position, and the letter 't'
    cout << str[0] << " " << p << " " << *(p + 2) << endl; // 'A', pointer to "A string.", 't'

    // Update the pointer to point to p + 2
    p += 2;

    // Print the pointer and the letters 'r' and 'g' using the updated pointer
    cout << p << " " << *(p + 2) << " " << *(p + 4) << endl; // Pointer to "string.", 'r', 'g'

    return 0;
}