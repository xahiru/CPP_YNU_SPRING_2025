#include <iostream>
using namespace std;

int main() {
    int arr[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> arr[i][j];
    
    swap(arr[1], arr[2]);
    for (int i = 0; i < 4; ++i)
        swap(arr[i][1], arr[i][2]);
    
    cout << "[";
    for (int i = 0; i < 4; ++i) {
        cout << "[";
        for (int j = 0; j < 4; ++j) {
            cout << arr[i][j];
            if (j != 3) cout << ", ";
        }
        cout << "]" << (i != 3 ? " , " : "");
    }
    cout << "]";
}