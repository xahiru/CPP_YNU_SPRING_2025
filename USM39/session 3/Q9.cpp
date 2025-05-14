#include <iostream>
#include <unordered_set>
using namespace std;

void printUniqueElements(int arr[], int size) {
    unordered_set<int> unique;
    
    for (int i = 0; i < size; i++) {
        unique.insert(arr[i]);
    }
    
    cout << "Unique elements of the said array: ";
    for (int num : unique) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    printUniqueElements(arr, size);
    
    return 0;
}