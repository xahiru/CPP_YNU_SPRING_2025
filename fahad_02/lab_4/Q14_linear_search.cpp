#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key;
    bool found = false;

    cout << "Enter the element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}