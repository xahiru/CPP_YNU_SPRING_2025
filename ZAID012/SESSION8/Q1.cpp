#include <iostream>
using namespace std;

void printMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[4][4]) {
    int transpose[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    cout << "Transposed Matrix:" << endl;
    printMatrix(transpose);
}

int main() {
    int matrix[4][4] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    transposeMatrix(matrix);
    
    return 0;
}
