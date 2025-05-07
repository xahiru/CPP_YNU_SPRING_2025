#include <iostream>
#include <vector>
using namespace std;

// Function to find elements smaller than their adjacent neighbors
vector<int> findSmallerThanNeighbors(const vector<int>& vec) {
    vector<int> result; // Vector to store the result

    // Check for elements in the vector
    for (size_t i = 1; i < vec.size() - 1; i++) {
        // Check if the current element is smaller than its neighbors
        if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]) {
            result.push_back(vec[i]); // Add to result if condition is met
        }
    }

    return result; // Return the result vector
}

int main() {
    // Original vector elements
    vector<int> vec = {1, 2, 5, 0, 3, 1, 7};

    cout << "Original Vector elements: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Find elements smaller than their neighbors
    vector<int> smallerElements = findSmallerThanNeighbors(vec);

    // Output the result
    cout << "Vector elements that are smaller than their adjacent neighbours: ";
    for (int num : smallerElements) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}