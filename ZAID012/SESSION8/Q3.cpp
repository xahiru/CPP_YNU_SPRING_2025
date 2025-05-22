#include <iostream>
using namespace std;

int diagonalSum(int arr[4][4]) {
    int mainDiagonal = 0, secondaryDiagonal = 0;
    for (int i = 0; i < 4; i++) {
        mainDiagonal += arr[i][i];
        secondaryDiagonal += arr[i][3 - i];
    }
    return mainDiagonal + secondaryDiagonal;
}

int main() {
    int arr[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    cout << "Diagonal Sum: " << diagonalSum(arr) << endl;
    return 0;
}
