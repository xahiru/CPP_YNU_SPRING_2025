#include <iostream>
using namespace std;

const int SIZE = 4;

void swapMiddleRows(int mat[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        swap(mat[1][j], mat[2][j]);
    }
}

void swapMiddleColumns(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        swap(mat[i][1], mat[i][2]);
    }
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
    int mat1[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    cout << "Original matrix 1:" << endl;
    printMatrix(mat1);
    
    swapMiddleRows(mat1);
    swapMiddleColumns(mat1);
    
    cout << "Modified matrix 1:" << endl;
    printMatrix(mat1);
    cout << endl;
    
    // Test case 2
    int mat2[SIZE][SIZE] = {
        {0, 1, 4, 4},
        {12, 5, 14, 12},
        {20, 20, 21, 20},
        {1, 6, 8, 9}
    };
    
    cout << "Original matrix 2:" << endl;
    printMatrix(mat2);
    
    swapMiddleRows(mat2);
    swapMiddleColumns(mat2);
    
    cout << "Modified matrix 2:" << endl;
    printMatrix(mat2);
    
    return 0;
}