#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    unordered_set<int> seen;
    unordered_set<int> repeats;
    
    for(int i = 0; i < size; i++) {
        if(seen.find(arr[i]) != seen.end()) {
            repeats.insert(arr[i]);
        } else {
            seen.insert(arr[i]);
        }
    }
    
    cout << "Repeating elements: ";
    for(int num : repeats) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

