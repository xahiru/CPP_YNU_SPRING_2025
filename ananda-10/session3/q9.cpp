#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    int arr[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_set<int> seen;
    vector<int> uniqueElements;

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";

        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            uniqueElements.push_back(arr[i]);
        }
    }

    cout << "\nUnique elements of the said array: ";
    for (int num : uniqueElements) {
        cout << num << " ";
    }

    return 0;
}

