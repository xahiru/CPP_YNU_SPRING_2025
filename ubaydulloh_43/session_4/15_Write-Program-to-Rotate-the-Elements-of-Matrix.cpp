#include <iostream>
using namespace std;

void rotateMatrixClockwise(int matrix[][3], int rows, int cols, int k) {
    k = k % 4; // Поскольку вращение на 4 раза возвращает к исходному состоянию
    for (int r = 0; r < k; r++) {
        int temp[3][3];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[j][rows - 1 - i] = matrix[i][j];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
}

void printMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    int k = 2;

    rotateMatrixClockwise(matrix, 3, 3, k);
    cout << "Matrix after rotation:" << endl;
    printMatrix(matrix, 3, 3);

    return 0;
}