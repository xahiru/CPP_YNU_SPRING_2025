#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int mat[N][N];

    cout << "Enter the elements of a 4x4 matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    cout << "Transposed matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

