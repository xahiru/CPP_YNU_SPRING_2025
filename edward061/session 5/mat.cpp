#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Input an integer value: Create an n x n matrix by said integer:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}