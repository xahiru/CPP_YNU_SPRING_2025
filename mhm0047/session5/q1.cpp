#include <iostream>
#include <vector>
using namespace std;

vector<int> findElementsSmallerThanNeighbors(const vector<int>& nums) {
    vector<int> smallerElements;
    int n = nums.size();

    if (n < 3) {
        return smallerElements;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            smallerElements.push_back(nums[i]);
        }
    }

    return smallerElements;
}

int main() {
    vector<int> nums = {1, 2, 5, 0, 3, 1, 7};
    vector<int> smallerNumbers = findElementsSmallerThanNeighbors(nums);
    
    cout << "Elements smaller than their adjacent neighbors:\n";
    for (const int& num : smallerNumbers) {
        cout << num << endl;
    }

    return 0;
}
