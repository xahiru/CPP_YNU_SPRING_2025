#include <iostream>
using namespace std;

void printAlphabets(char c1, char c2) {
    for (char c = c1; c <= c2; c++) {
        cout << c << " ";
    }
}

int main() {
    char c1 = 'a', c2 = 'z';
    cout << "Alphabets from " << c1 << " to " << c2 << ": ";
    printAlphabets(c1, c2);
    cout << endl;
    
    char c3 = 'h', c4 = 'u';
    cout << "Alphabets from " << c3 << " to " << c4 << ": ";
    printAlphabets(c3, c4);
    cout << endl;
    
    return 0;
}