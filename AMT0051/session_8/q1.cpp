#include <iostream>
using namespace std;

const int SIZE = 4;

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[SIZE][SIZE], int trans[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            trans[j][i] = mat[i][j];
        }
    }
}

int main() {
    int mat[SIZE][SIZE] = {
        {0, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 1}
    };

    int trans[SIZE][SIZE];

    cout << "Original Matrix:\n";
    printMatrix(mat);

    transposeMatrix(mat, trans);

    cout << "\nTransposed Matrix:\n";
    printMatrix(trans);

    return 0;
}
