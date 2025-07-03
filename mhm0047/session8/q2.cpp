#include <iostream>
using namespace std;

int main() {
    int a[4][4] = {{1,2,3,4},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    int b[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    int res[4][4] = {{1,2,3,4},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    int mul[4][4] = {};

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                mul[i][j] += a[i][k] * b[k][j];

    bool match = true;
    for (int i = 0; i < 4 && match; i++)
        for (int j = 0; j < 4; j++)
            if (mul[i][j] != res[i][j])
                match = false;

    cout << (match ? "true" : "false");
    return 0;
}
