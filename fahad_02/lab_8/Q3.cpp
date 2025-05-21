#include <iostream>
using namespace std;

const int SIZE = 4;

int calculateDiagonalSums(int mat[SIZE][SIZE]) {
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    
    for (int i = 0; i < SIZE; i++) {
        // Main diagonal (i == j)
        mainDiagonalSum += mat[i][i];
        
        // Secondary diagonal (i + j == SIZE - 1)
        secondaryDiagonalSum += mat[i][SIZE - 1 - i];
    }
    
    return mainDiagonalSum + secondaryDiagonalSum;
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
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };
    
    // Test case 2
    int mat2[SIZE][SIZE] = {
        {3, 2, 1, 0},
        {0, 3, 2, 7},
        {4, 4, 2, 2},
        {5, 5, 3, 6}
    };
    
    // Test case 3
    int mat3[SIZE][SIZE] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };
    
    // Calculate and display results
    cout << "Test case 1:" << endl;
    printMatrix(mat1);
    cout << "Diagonal sum: " << calculateDiagonalSums(mat1) << endl << endl;
    
    cout << "Test case 2:" << endl;
    printMatrix(mat2);
    cout << "Diagonal sum: " << calculateDiagonalSums(mat2) << endl << endl;
    
    cout << "Test case 3:" << endl;
    printMatrix(mat3);
    cout << "Diagonal sum: " << calculateDiagonalSums(mat3) << endl;
    
    return 0;
}