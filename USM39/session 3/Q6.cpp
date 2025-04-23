#include <iostream>
#include <unordered_set>
using namespace std;

void findRepeatingElements(int arr[], int size) {
    unordered_set<int> seen;
    unordered_set<int> repeating;
    
    for (int i = 0; i < size; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            repeating.insert(arr[i]);
        } else {
            seen.insert(arr[i]);
        }
    }
    
    cout << "Repeating elements: ";
    for (int num : repeating) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    findRepeatingElements(arr, size);
    
    return 0;
}