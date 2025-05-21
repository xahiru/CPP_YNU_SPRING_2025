#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    
    // Perform linear search
    int result = linearSearch(arr, size, key);
    
    // Display result
    if (result != -1) {
        cout << key << " found at index " << result << endl;
    } else {
        cout << key << " not found in the array" << endl;
    }
    
    return 0;
}