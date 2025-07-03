#include <iostream>
using namespace std;

const int SIZE = 4;

bool areMatricesEqual(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void multiplyMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int res[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            res[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
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
    
    int product[SIZE][SIZE];
    multiplyMatrices(mat1, mat2, product);
    
    cout << (areMatricesEqual(product, res) ? "true" : "false") << endl;
    return 0;
}