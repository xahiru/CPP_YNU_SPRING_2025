#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Input the integer n
    cin >> n;

    // Check if n is between 1 and 9, and print corresponding word
    if (n > 1 && n < 9) {
        switch (n) {
            case 2: cout << "two"; break;
            case 3: cout << "three"; break;
            case 4: cout << "four"; break;
            case 5: cout << "five"; break;
            case 6: cout << "six"; break;
            case 7: cout << "seven"; break;
            case 8: cout << "eight"; break;
            default: break;  // Case for numbers less than 1 or greater than 9
        }
    } else {
        // If n is greater than 9
        cout << "Greater than 9";
    }

    return 0;
}
