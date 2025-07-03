#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // Sample array
    vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};

    // Use a set to store unique elements
    set<int> uniqueElements;

    // Insert elements into the set
    for (int num : arr) {
        uniqueElements.insert(num);
    }

    // Print the original array
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Print unique elements
    cout << "Unique elements of the said array: ";
    for (int num : uniqueElements) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}