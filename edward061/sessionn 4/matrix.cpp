#include <iostream>
using namespace std;

void rotateMatrixBy90Clockwise(int matrix[3][3], int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {

            int temp = matrix[i][j];

            matrix[i][j] = matrix[n - j - 1][i];

            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            
            matrix[j][n - i - 1] = temp;
        }
    }
}

void printMatrix(int matrix[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int n = 3;  
    int K = 2; 

    for (int i = 0; i < K; i++) {
        rotateMatrixBy90Clockwise(matrix, n);
    }

    cout << "Rotated Matrix: " << endl;
    printMatrix(matrix, n);
    
    return 0;
}