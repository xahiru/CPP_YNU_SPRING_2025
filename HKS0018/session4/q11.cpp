#include <iostream>
using namespace std;

int main() {
    // Declare and initialize a constant character array (string) "A string."
    const char str[] = "A string.";
  
    const char* ptr = str; // Declares a pointer 'ptr' and initialize it to point to the start of 'str'

    // 1. str[0] First character of the array ('A')
    // 2. *ptr Value at the current pointer position (also 'A', since ptr points to str[0])
    // 3. The literal character 't'
    cout << str[0] << " " << *ptr << " " << 't' << endl;
    ptr += 2;
    cout << *ptr << " " << 'r' << " " << 'g' << endl;

    return 0;
}