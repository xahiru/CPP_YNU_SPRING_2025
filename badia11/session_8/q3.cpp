#include <iostream>
using namespace std;

int main() {
    int arr[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    int mainDiag = 0, secDiag = 0;

    for(int i = 0; i < 4; i++) {
        mainDiag += arr[i][i];
        secDiag += arr[i][3 - i];
    }

    cout << "Sum = " << mainDiag + secDiag;
    return 0;
}
