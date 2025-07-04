#include <iostream>
using namespace std;

void middleSwap(int arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        swap(arr[1][i], arr[2][i]);
    }
    for (int i = 0; i < 4; i++) {
        swap(arr[i][1], arr[i][2]);
    }
}

int main() {
    int arr[4][4] = {{1, 2, 3, 4}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    middleSwap(arr);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}