#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[8] = {10, 25, 30, 5, 18, 60, 45, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int firstMax, secondMax, thirdMax;
    firstMax = secondMax = thirdMax = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] < firstMax) {
            thirdMax = secondMax;
            secondMax = arr[i];
        }
        else if(arr[i] > thirdMax && arr[i] < secondMax) {
            thirdMax = arr[i];
        }
    }

    cout << "Three largest elements are: " << firstMax << ", " << secondMax << ", " << thirdMax << endl;
    return 0;
}
