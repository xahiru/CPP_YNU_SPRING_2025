#include <bits/stdc++.h>

using namespace std;


int RecSum(vector<int> &arr, int n)
{
    if (n <= 0)
        return 0;
    return (RecSum(arr, n - 1) + arr[n - 1]);
}

int arraysum(vector<int> &arr){
    return RecSum(arr,arr.size());
}

// Driver code
int main()
{
    vector<int> arr = { 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10};
    cout<<arraysum(arr)<<'\n';

    return 0;
}
