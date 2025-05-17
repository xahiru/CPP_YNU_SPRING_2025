#include <iostream>
using namespace std;

const int SIZE = 4;

void transposeMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            // Swap mat[i][j] and mat[j][i]
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
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
    int mat1[SIZE][SIZE] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };
    
    int mat2[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    
    int mat3[SIZE][SIZE] = {
        {0, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 1},
        {0, 1, 0, 1}
    };
    
    // Test case 1
    cout << "Original matrix 1:" << endl;
    printMatrix(mat1);
    transposeMatrix(mat1);
    cout << "Transposed matrix 1:" << endl;
    printMatrix(mat1);
    
    // Reset matrix 1 for demonstration
    int mat1_reset[SIZE][SIZE] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };
    
    // Test case 2
    cout << "\nOriginal matrix 2:" << endl;
    printMatrix(mat2);
    transposeMatrix(mat2);
    cout << "Transposed matrix 2:" << endl;
    printMatrix(mat2);
    
    // Test case 3
    cout << "\nOriginal matrix 3:" << endl;
    printMatrix(mat3);
    transposeMatrix(mat3);
    cout << "Transposed matrix 3:" << endl;
    printMatrix(mat3);
    
    return 0;
}