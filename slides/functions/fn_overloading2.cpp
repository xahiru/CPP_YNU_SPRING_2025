#include <iostream>
#include <string>
using namespace std;

// Function to print a string
void print(string s) {
    cout << s << "\n";
}

// Function to print an integer
void print(int x) {
    cout << x << "\n";
}

// Function to print a character
void print(char c) {
    cout << c << "\n";
}

int main() {
    print('a');  // Calls the print(char) function
    print(10);   // Calls the print(int) function
    print("YNU");  // Calls the print(string) function

    return 0;
}