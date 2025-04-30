#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkConsecutive(vector<int>& vec) {
    if (vec.empty()) {
        return false;
    }

    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] != vec[i - 1] + 1) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> vec = {1, 2, 5, 0, 3, 6, 7};

    if (checkConsecutive(vec)) {
        cout << "Check consecutive numbers in the said vector! 1" << endl;
    } else {
        cout << "Check consecutive numbers in the said vector! 0" << endl;
    }

    return 0;
}