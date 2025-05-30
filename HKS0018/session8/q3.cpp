#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(const vector<vector<int>>& arr) {
    int n = arr.size();
    int main_sum = 0, secondary_sum = 0;
    
    for (int i = 0; i < n; i++) {
        main_sum += arr[i][i];
        secondary_sum += arr[i][n - 1 - i];
    }

    return main_sum + secondary_sum;
}

int main() {

    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };

    cout << diagonalSum(arr) << endl;
    
    
    return 0;
}