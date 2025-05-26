#include <iostream>
using namespace std;

int diagonalSum(int arr[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += arr[i][i]; // Main diagonal
        sum += arr[i][3 - i]; // Secondary diagonal
    }
    return sum;
}

int main() {
    int arr[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    cout << diagonalSum(arr) << endl; // Output: 32
    return 0;
}
