#include <iostream>
using namespace std;

void findPairsWithSum(int arr[], int size, int target) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                cout << arr[i] << "," << arr[j] << endl;
                count++;
            }
        }
    }
    
    cout << "Number of pairs whose sum equal to " << target << ": " << count << endl;
}

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Array pairs whose sum equal to " << target << ":" << endl;
    findPairsWithSum(arr, size, target);
    
    return 0;
}