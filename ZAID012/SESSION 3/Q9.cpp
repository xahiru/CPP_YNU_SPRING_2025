#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    unordered_set<int> unique_elements;
    
    for(int i = 0; i < size; i++) {
        unique_elements.insert(arr[i]);
    }
    
    cout << "Unique elements of the said array: ";
    for(int elem : unique_elements) {
        cout << elem << " ";
    }
    cout << endl;
    
    return 0;
}
