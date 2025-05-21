#include <iostream>
using namespace std;

int main() {
    int mat[4][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        sum += mat[i][i];
        sum += mat[i][3 - i];
    }

    cout << sum;
    return 0;
}
