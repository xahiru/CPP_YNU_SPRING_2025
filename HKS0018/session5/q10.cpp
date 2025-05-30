#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;

    if (n <= 0 || n > 26) {
        cout << "Please enter a number between 1 and 26." << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= 2 * (n - i); space++) {
            cout << " ";
        }

        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            cout << ch++ << " ";
        }
        
        ch -= 2;
        for (int k = 1; k < i; k++) {
            cout << ch-- << " ";
        }

        cout << endl;
    }

    return 0;
}