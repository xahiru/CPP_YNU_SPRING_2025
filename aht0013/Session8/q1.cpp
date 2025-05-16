#include <iostream>
using namespace std;

int main() {
    int mat[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};
    int trans[4][4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            trans[i][j] = mat[j][i];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
    return 0;
}