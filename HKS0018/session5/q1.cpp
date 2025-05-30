#include <iostream>
#include <vector>

using namespace std;

vector<int> findElementsSmallerThanNeighbours(const vector<int>& nums) {
    vector<int> result;
    
    // Check elements from index 1 to n-2 
    for (size_t i = 1; i < nums.size() - 1; ++i) {
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            result.push_back(nums[i]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums;
    int n, num;
    
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    
    // Get vector elements from user
    cout << "Enter " << n << " integers separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    
    // Find elements smaller than neighbors
    vector<int> result = findElementsSmallerThanNeighbours(nums);
    
    // show the results
    cout << "\nOriginal Vector elements: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    if (result.empty()) {
        cout << "No elements are smaller than both their adjacent neighbors." << endl;
    } else {
        cout << "Vector elements that are smaller than their adjacent neighbours: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}