#include <iostream>
using namespace std;

const int SIZE = 4;

void multiplyMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

bool compareMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(int mat[SIZE][SIZE]) {
    cout << "[";
    for (int i = 0; i < SIZE; i++) {
        if (i != 0) cout << " ";
        cout << "[";
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j];
            if (j != SIZE - 1) cout << ", ";
        }
        cout << "]";
        if (i != SIZE - 1) cout << ", " << endl;
    }
    cout << "]" << endl;
}

int main() {
    // Test case 1
    int mat1_1[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    int mat2_1[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    int res1[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    // Test case 2
    int mat1_2[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {1, 2, 3, 4}
    };
    
    int mat2_2[SIZE][SIZE] = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    
    int res2[SIZE][SIZE] = {
        {0, 1, 4, 4},
        {12, 5, 14, 12},
        {20, 20, 21, 20},
        {1, 6, 8, 9}
    };
    
    // Calculate actual results
    int actual1[SIZE][SIZE], actual2[SIZE][SIZE];
    
    // Test case 1
    multiplyMatrices(mat1_1, mat2_1, actual1);
    cout << "Test case 1:" << endl;
    cout << "Expected result:" << endl;
    printMatrix(res1);
    cout << "Actual result:" << endl;
    printMatrix(actual1);
    cout << "Comparison result: " << (compareMatrices(actual1, res1) ? "true" : "false") << endl << endl;
    
    // Test case 2
    multiplyMatrices(mat1_2, mat2_2, actual2);
    cout << "Test case 2:" << endl;
    cout << "Expected result:" << endl;
    printMatrix(res2);
    cout << "Actual result:" << endl;
    printMatrix(actual2);
    cout << "Comparison result: " << (compareMatrices(actual2, res2) ? "true" : "false") << endl;
    
    return 0;
}