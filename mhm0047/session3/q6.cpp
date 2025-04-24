#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findRepeating(int arr[], int n) {
    vector<int> repeating;   
    
    for(int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;
        if(arr[index] < 0) {
            repeating.push_back(abs(arr[i]));
        } else {
            arr[index] = -arr[index];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            arr[i] = -arr[i];
        }
    }
    
    sort(repeating.begin(), repeating.end());
    cout << "Repeating elements: ";
    for(int num : repeating) {
        cout << num << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    findRepeating(arr, n);
    
    return 0;
}
