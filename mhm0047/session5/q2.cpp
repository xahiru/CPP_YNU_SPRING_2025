#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, n));

    cout << "Create an n x n matrix by said integer:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
