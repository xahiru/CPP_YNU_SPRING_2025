#include <iostream>
using namespace std;

int main() {
    int mat[4][4];

    // Read input matrix
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> mat[i][j];

    // Print transposed matrix directly
    cout << "[";
    for (int i = 0; i < 4; ++i) {
        cout << "[";
        for (int j = 0; j < 4; ++j) {
            cout << mat[j][i];  // Access elements in transposed order
            if (j < 3) cout << ", ";
        }
        cout << "]";
        if (i < 3) cout << ", ";
    }
    cout << "]";

    return 0;
}