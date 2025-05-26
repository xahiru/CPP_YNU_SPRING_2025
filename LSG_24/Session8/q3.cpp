#include <iostream>
using namespace std;

const int SIZE = 4;

int diagonalSum(int arr[SIZE][SIZE]) {
    int mainDiag = 0, secondaryDiag = 0;
    for (int i = 0; i < SIZE; i++) {
        mainDiag += arr[i][i];
        secondaryDiag += arr[i][SIZE - 1 - i];
    }
    return mainDiag + secondaryDiag;
}

int main() {
    int arr[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };
    
    cout << diagonalSum(arr) << endl;
    return 0;
}