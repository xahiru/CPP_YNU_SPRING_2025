#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int main() {
    int n, K;
    cout << "Enter array size (n): ";
    cin >> n;
    cout << "Enter data type (K = 1 for int, K = 2 for float): ";
    cin >> K;

    if (K == 1) {
        int arr[100];  
        cout << "Enter " << n << " integer elements:\n";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << "Maximum element: " << findMax<int>(arr, n) << endl;
    }
    else if (K == 2) {
        float arr[100];  
        cout << "Enter " << n << " float elements:\n";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << "Maximum element: " << findMax<float>(arr, n) << endl;
    }
    else {
        cout << "Invalid data type selection!" << endl;
    }

    return 0;
}


