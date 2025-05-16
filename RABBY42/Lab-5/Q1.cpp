#include <iostream>
#include <vector>
using namespace std;

vector<int> findElements(const vector<int>& vec) {
    vector<int> res;
    if (vec.size() < 3) return res;
    for (size_t i = 1; i < vec.size()-1; ++i) {
        if (vec[i] < vec[i-1] && vec[i] < vec[i+1])
            res.push_back(vec[i]);
    }
    return res;
}

int main() {
    vector<int> vec = {1, 2, 5, 0, 3, 1, 7};
    auto res = findElements(vec);
    for (int num : res) cout << num << " ";
    return 0;
}