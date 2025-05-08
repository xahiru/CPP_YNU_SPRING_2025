#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Dynamically allocate array
    int* squares = new int[n];

    // Fill with squares
    for (int i = 0; i < n; i++) {
        squares[i] = (i + 1) * (i + 1);
    }

    // Output results
    cout << "Squares: ";
    for (int i = 0; i < n; i++) {
        cout << squares[i] << " ";
    }

    // Free memory
    delete[] squares;

    return 0;
}
