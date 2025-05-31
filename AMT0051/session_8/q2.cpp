#include <iostream>
using namespace std;

const int SIZE = 4;

bool isMatrixMultiplicationCorrect(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int res[SIZE][SIZE]) {
    int product[SIZE][SIZE] = {0};

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (product[i][j] != res[i][j])
                return false;
        }
    }

    return true;
}

int main() {
    int mat1[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int mat2[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int res[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    if (isMatrixMultiplicationCorrect(mat1, mat2, res)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}
