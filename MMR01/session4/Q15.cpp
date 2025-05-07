#include <iostream>
using namespace std;

// Function to rotate the matrix clockwise
void rotateMatrixClockwise(int matrix[][3], int n, int k) {
    // Normalize k to be within the range of 0 to 3 (since 4 rotations bring it back to original)
    k = k % 4;

    for (int r = 0; r < k; r++) {
        // Create a temporary matrix to store the rotated values
        int temp[3][3];

        // Rotate the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }

        // Copy the rotated values back to the original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define a 3x3 matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int k = 2; // Number of rotations

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, 3);

    // Rotate the matrix
    rotateMatrixClockwise(matrix, 3, k);

    cout << "Matrix after " << k << " clockwise rotations:" << endl;
    printMatrix(matrix, 3);

    return 0;
}