#include <iostream>
using namespace std;

void transpose(int mat[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            swap(mat[i][j], mat[j][i]);
}

int main() {
    int mat[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};
    transpose(mat);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}