#include <iostream>
using namespace std;

int main() {
    int arr[4][4];

    cout << "Enter the elements of a 4x4 matrix:" << endl;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];

    for (int j = 0; j < 4; j++) {
        int temp = arr[1][j];
        arr[1][j] = arr[2][j];
        arr[2][j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int temp = arr[i][1];
        arr[i][1] = arr[i][2];
        arr[i][2] = temp;
    }

    cout << "Output matrix after middle row and column swap:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}

