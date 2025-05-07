#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Input an integer value: ";
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n, n));
    
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}