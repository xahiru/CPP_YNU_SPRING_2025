#include <iostream>
using namespace std;

int main() {
    const char* str = "A string.";
    const char* ptr = str;  // Initialize pointer to start of string
    
    // First line: index 0, pointer position, and 't'
    cout << str[0] << " " << *ptr << " " << 't' << endl;
    
    // Update pointer position (+2)
    ptr += 2;
    
    // Second line: current pointer position, 'r' and 'g'
    cout << *ptr << " " << 'r' << " " << 'g' << endl;
    
    return 0;
}