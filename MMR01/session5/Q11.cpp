#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    // Validate input
    if (n <= 0 || n >= 26) {
        cout << "Please enter a number between 1 and 25." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int j = 0; j < 2*(n-i-1); j++) {
            cout << " ";
        }

        // Print increasing letters
        char ch = 'A';
        for (int j = 0; j <= i; j++) {
            cout << ch++ << " ";
        }

        // Print decreasing letters
        ch -= 2;
        for (int j = 0; j < i; j++) {
            cout << ch-- << " ";
        }

        cout << endl;
    }

    return 0;
}