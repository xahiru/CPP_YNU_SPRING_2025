#include <iostream>
using namespace std;

void rotateClockwise(int mat[3][3], int k) {
    k = k % 4; // Reduce rotations to equivalent in 0-3 range
    while (k--) {
        // Transpose the matrix
        for (int i = 0; i < 3; i++) {
            for (int j = i; j < 3; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3/2; j++) {
                swap(mat[i][j], mat[i][3-j-1]);
            }
        }
    }
}

int main() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 2;
    
    rotateClockwise(mat, k);
    
    cout << "Matrix = ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl << "        ";
    }
    return 0;
}
