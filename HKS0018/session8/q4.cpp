#include <iostream>
#include <vector>

using namespace std;

void swapMiddleRowsAndColumns(vector<vector<int>>& arr) 
{
    for (int j = 0; j < 4; j++) {
        swap(arr[1][j], arr[2][j]);
    }

    for (int i = 0; i < 4; i++) {
        swap(arr[i][1], arr[i][2]);
    }
}

void printMatrix(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << " ";
        }

        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 4, 4},
        {12, 5, 14, 12},
        {20, 20, 21, 20},
        {1, 6, 8, 9}
    };

    swapMiddleRowsAndColumns(arr);
    printMatrix(arr);
    
    return 0;
}