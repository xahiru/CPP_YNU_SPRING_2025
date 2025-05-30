#include <iostream>
using namespace std;

bool checkProduct(int mat1[4][4], int mat2[4][4], int res[4][4]) {
    int product[4][4] = {0};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                product[i][j] += mat1[i][k] * mat2[k][j];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (product[i][j] != res[i][j])
                return false;
    return true;
}
