#include <iostream>
using namespace std;

int main() {
    string str = "A string.";
    char* ptr = &str[0];

    cout << *ptr << " " << (ptr + 1) << " " << *(ptr + 2) << endl; // Print first character, pointer position, and 't'
    ptr += 2; // Update pointer to point to the character after 't'
    cout << ptr << " " << *(ptr + 1) << " " << *(ptr + 3) << endl; // Print pointer position and characters 'r' and 'g'
    
    return 0;
}