#include <iostream>
#include <vector>
using namespace std;

vector<int> findSmallerElements(const vector<int>& vec) {
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
    vector<int> smaller = findSmallerElements(vec);
    cout << "Elements smaller than adjacent neighbours: ";
    for (int num : smaller) {
        cout << num << " ";
    }
    return 0;
}
