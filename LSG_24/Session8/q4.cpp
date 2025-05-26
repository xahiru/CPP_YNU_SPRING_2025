#include <iostream>
using namespace std;

const int SIZE = 4;

void middleSwap(int arr[SIZE][SIZE]) {
    // Swap middle rows (1 and 2 in 0-based indexing)
    for (int j = 0; j < SIZE; j++) {
        swap(arr[1][j], arr[2][j]);
    }
    
    // Swap middle columns (1 and 2 in 0-based indexing)
    for (int i = 0; i < SIZE; i++) {
        swap(arr[i][1], arr[i][2]);
    }
}

void printMatrix(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    middleSwap(arr);
    printMatrix(arr);
    return 0;
}