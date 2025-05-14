#include <iostream>
using namespace std;

void printAlphabets(char c1, char c2) {
    for (char c = c1; c <= c2; ++c) {
        cout << c << " ";
    }
}

int main() {
    // Test cases
    printAlphabets('a', 'z');
    cout << endl;  // To separate test cases in output
    printAlphabets('h', 'u');
    return 0;
}