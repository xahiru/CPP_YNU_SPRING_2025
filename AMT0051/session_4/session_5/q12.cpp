#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int* squares = new int[n];

    for (int i = 0; i < n; i++) {
        squares[i] = (i + 1) * (i + 1);
    }

    cout << "Squares: ";
    for (int i = 0; i < n; i++) {
        cout << squares[i] << " ";
    }
    cout << endl;

    delete[] squares;

    return 0;
}
