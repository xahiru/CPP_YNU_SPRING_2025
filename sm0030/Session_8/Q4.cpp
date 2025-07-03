#include <iostream>
using namespace std;

int main() {
    int mat[4][4] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    // Swap 2nd and 3rd row
    for (int j = 0; j < 4; ++j)
        swap(mat[1][j], mat[2][j]);

    // Swap 2nd and 3rd column
    for (int i = 0; i < 4; ++i)
        swap(mat[i][1], mat[i][2]);

    cout << "Modified matrix:\n";
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
