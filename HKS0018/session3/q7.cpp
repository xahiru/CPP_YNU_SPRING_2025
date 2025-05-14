#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for (int j = 0; i < n - 1; i++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }

        }
    }
}

int main (){
    int arr[]={1, 5, 7, 5, 8,11,13};

    int n = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 12;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int left = 0;
    int right = n - 1;
    int pairCount = 0;

    cout << "Array pairs whose sum equal to " << targetSum << ": ";
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == targetSum) {
            cout << "(" << arr[left] << ", " << arr[right] << ") ";
            pairCount++;
            left++;
            right--;
        }
        else if (currentSum < targetSum) {
            left++; 
        }
        else {
            right--; 
        }
    }

    cout << endl;
    cout << "Number of pairs whose sum equal to " << targetSum << ": " << pairCount << endl;

    return 0;
}