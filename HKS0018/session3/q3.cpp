#include <iostream>

using namespace std;

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};


    int n = sizeof(arr) / sizeof(arr[0]);


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {             
                swap(arr[j], arr[j + 1]);   //swaping elements in order
            }
        }
    }

    // After sorting, the second smallest will be at index 1
    if (n < 2) {
        cout << "Array should have at least two elements." << endl;
        return -1;
    }

    // check if the smallest num and 2nd small number are same if the smallest and second smallaest number
    //are same next smallest number.
    if (arr[0] == arr[1]) {
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                cout << "Second smallest number: " << arr[i] << endl;

                return 0;
            }
        }
        cout << "No second smallest element found." << endl;
        return -1;
    }

    cout << "The Second smallest number: " << arr[1] << endl;



    return 0;
}
