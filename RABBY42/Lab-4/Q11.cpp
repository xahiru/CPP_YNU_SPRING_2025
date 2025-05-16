#include <iostream>
using namespace std;

int main() {
    const char* str = "A string.";
    const char* ptr = str; // Initialize pointer to the start of the string

    // First line: index 0 (A), current pointer value (A), and 't' (index 3)
    cout << str[0] << *ptr << *(ptr + 3) << endl;

    ptr += 2; // Move pointer 2 positions ahead (now points to 's')

    // Second line: current pointer value (s), 'r' (ptr + 2), and 'g' (ptr + 5)
    cout << *ptr << *(ptr + 2) << *(ptr + 5) << endl;

    return 0;
}