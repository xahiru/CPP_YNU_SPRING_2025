#include <iostream>
using namespace std;

bool isEqual(int mat1[4][4], int mat2[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mat1[i][j] != mat2[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    int mat1[4][4], mat2[4][4], res[4][4], actual[4][4];

    cout << "Enter elements of matrix 1 (4x4):\n";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> mat1[i][j];

    cout << "Enter elements of matrix 2 (4x4):\n";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> mat2[i][j];

    cout << "Enter expected result matrix (4x4):\n";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> res[i][j];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            actual[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                actual[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    if (isEqual(actual, res))
        cout << "Output: true\n";
    else
        cout << "Output: false\n";

    return 0;
}

