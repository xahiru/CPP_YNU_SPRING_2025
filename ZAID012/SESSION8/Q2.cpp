#include <iostream>
using namespace std;

bool multiplyMatrices(int mat1[4][4], int mat2[4][4], int res[4][4]) {
    int temp[4][4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                temp[i][j] += mat1[i][k] * mat2[k][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (temp[i][j] != res[i][j]) return false;

    return true;
}

int main() {
    int mat1[4][4] = {{1, 2, 3, 4}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    int mat2[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    int res[4][4] = {{1, 2, 3, 4}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    cout << (multiplyMatrices(mat1, mat2, res) ? "true" : "false") << endl;
    return 0;
}
