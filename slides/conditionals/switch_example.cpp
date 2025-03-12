#include <iostream>
using namespace std;

int main() {
    char c = 'B';
    switch (c) {
        
    // if the input character is A then print YNU
    case 'A':
        cout << "YNU";
        break;

    // if the input character is B then print
    // Yunnan University
    case 'B':
        cout << "Yunnan University";
        break;
    default:
        
        // if the input character is invalid then print
        // invalid input
        cout << "invalid input";
    }
    return 0;
}