#include <iostream>
using namespace std;

void rotateMatrix(int matrix[3][3], int k) {
    for (int r = 0; r < k; r++) {
        int temp = matrix[0][0];
        for (int i = 0; i < 2; i++) matrix[i][0] = matrix[i + 1][0];
        for (int i = 0; i < 2; i++) matrix[2][i] = matrix[2][i + 1];
        for (int i = 2; i > 0; i--) matrix[i][2] = matrix[i - 1][2];
        for (int i = 2; i > 0; i--) matrix[0][i] = matrix[0][i - 1];
        matrix[1][1] = temp; 
    }
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(matrix, 2);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;  
    }
    return 0;
}
