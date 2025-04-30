#include <iostream>
#include <vector>
using namespace std;

vector<int> findSmallerThanNeighbors(const vector<int>& vec) {
    vector<int> result;

    for (size_t i = 1; i < vec.size() - 1; ++i) {
    
        if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]) {
            result.push_back(vec[i]);
        }
    }

    return result;
}

int main() {
    vector<int> vec = {1, 2, 5, 0, 3, 1, 7};

    vector<int> result = findSmallerThanNeighbors(vec);

    cout << "Original Vector elements:\n";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Vector elements that are smaller than its adjacent neighbours:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}