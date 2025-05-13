#include <vector>
#include <algorithm>
using namespace std;

bool isConsecutive(vector<int> vec) {
    if (vec.empty()) return false;
    sort(vec.begin(), vec.end());
    for (size_t i = 1; i < vec.size(); ++i)
        if (vec[i] == vec[i-1]) return false;
    int min = vec[0], max = vec.back();
    return (max - min) == (vec.size() - 1);
}