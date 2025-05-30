#include <iostream>
#include <vector>

using namespace std;

bool multiplyAndCheck(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, const vector<vector<int>>& res) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            if (sum != res[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    vector<vector<int>> mat2 = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    vector<vector<int>> res = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    cout << (multiplyAndCheck(mat1, mat2, res) ? "true" : "false") << endl;
    
    return 0;
}