#include <iostream>
#include <vector>
using namespace std;

// Function to rotate the matrix clockwise
void rotateMatrixClockwise(vector<vector<int>>& matrix, int K) {
    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Normalize K to avoid unnecessary full rotations
    K = K % 4; // Since rotating 4 times results in the same matrix

    for (int k = 0; k < K; ++k) {
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < m; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define the matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int K = 2; // Number of rotations

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Rotate the matrix clockwise K times
    rotateMatrixClockwise(matrix, K);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}