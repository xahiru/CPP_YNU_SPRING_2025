#include <iostream>
using namespace std;

void middleSwap(int arr[4][4]) {
    // Swap 2nd and 3rd rows
    for (int j = 0; j < 4; j++)
        swap(arr[1][j], arr[2][j]);
    
    // Swap 2nd and 3rd columns
    for (int i = 0; i < 4; i++)
        swap(arr[i][1], arr[i][2]);
}

int main() {
    int arr[4][4] = {{0, 1, 4, 4}, {12, 5, 14, 12}, {20, 20, 21, 20}, {1, 6, 8, 9}};
    middleSwap(arr);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}