#include <iostream>
using namespace std;

int main() {
    int arr[4][4];
    int mainDiagonalSum = 0, secondaryDiagonalSum = 0;

    cout << "Enter the elements of a 4x4 matrix:" << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        mainDiagonalSum += arr[i][i];          
        secondaryDiagonalSum += arr[i][3 - i];  
    }

    int totalSum = mainDiagonalSum + secondaryDiagonalSum;
    cout << "Output: " << totalSum << endl;

    return 0;
}

