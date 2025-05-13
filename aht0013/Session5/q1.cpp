#include <iostream>
#include <vector>
using namespace std;

vector<int> findSmallerThanNeighbours(const vector<int>& v) {
    vector<int> result;
    if (v.size() < 3) return result;
    
    for (size_t i = 1; i < v.size() - 1; ++i) {
        if (v[i] < v[i-1] && v[i] < v[i+1]) {
            result.push_back(v[i]);
        }
    }
    return result;
}

int main() {
    vector<int> v = {1, 2, 5, 0, 3, 1, 7};
    vector<int> result = findSmallerThanNeighbours(v);
    
    cout << "Vector elements that are smaller than its adjacent neighbours:\n";
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}