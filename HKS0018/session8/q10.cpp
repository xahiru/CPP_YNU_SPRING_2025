#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void sortArray(T arr[], int n) {
    sort(arr, arr + n);
}

int main() {
    int n;
    cin >> n;

    // Determine the type of the array
    string firstElement;
    cin >> firstElement;

    bool isInteger = true;
    for (char c : firstElement) {
        if (c == '.' || c == '-' && &c != &firstElement[0]) {
            isInteger = false;
            break;
        }
    }
    bool isFloat = false;
    if (!isInteger) {
        isFloat = true;
        for (char c : firstElement) {
            if (c == '.') {
                isFloat = true;
                break;

            }
        }
    }

    if (isInteger) {
        int* arr = new int[n];
        arr[0] = stoi(firstElement);
        for (int i = 1; i < n; ++i) {
            cin >> arr[i];
        }
        sortArray(arr, n);
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        delete[] arr;
    } else if (isFloat) {
        float* arr = new float[n];
        arr[0] = stof(firstElement);
        for (int i = 1; i < n; ++i) {
            cin >> arr[i];
        }
        sortArray(arr, n);
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        delete[] arr;
    } else {
        string* arr = new string[n];
        arr[0] = firstElement;
        for (int i = 1; i < n; ++i) {
            cin >> arr[i];
        }
        sortArray(arr, n);
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        delete[] arr;
    }

    cout << endl;

 
    return 0;
    
}