#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkConsecutive(vector<int> &vec) {
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1] + 1) return false;
    }
    return true;
}

int main() {
    vector<int> vec = {1, 2, 5, 0, 3, 6, 7};
    cout << checkConsecutive(vec) << endl;
    return 0;
}
