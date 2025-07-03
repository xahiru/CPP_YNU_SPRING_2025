#include<iostream>
using namespace std;

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    // Swap 2nd (index 1) and 3rd (index 2) row
    for (int i = 0; i < 4; i++)
        swap(arr[1][i], arr[2][i]);

    // Swap 2nd (index 1) and 3rd (index 2) column
    for (int i = 0; i < 4; i++)
        swap(arr[i][1], arr[i][2]);

    cout << "Modified matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
