#include <iostream>
using namespace std;

int main() {
    int mat1[4][4], mat2[4][4], res[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> mat1[i][j];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> mat2[i][j];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> res[i][j];
    
    int product[4][4] = {0};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                product[i][j] += mat1[i][k] * mat2[k][j];
    
    bool equal = true;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (product[i][j] != res[i][j])
                equal = false;
    
    cout << (equal ? "true" : "false");
}