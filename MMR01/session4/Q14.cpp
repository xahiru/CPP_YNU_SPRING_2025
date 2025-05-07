#include <iostream>
using namespace std;

int main() {
    // Initialize the array
    int arr[] = {10, 11, 7, 8, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int elementToSearch;
    
    // Prompt the user to enter the element to be searched
    cout << "Element to be Searched: ";
    cin >> elementToSearch;

    // Perform linear search
    bool found = false; // Flag to indicate if the element is found
    int index = -1; // Variable to store the index of the found element

    for (int i = 0; i < size; i++) {
        if (arr[i] == elementToSearch) {
            found = true;
            index = i; // Store the index of the found element
            break; // Exit the loop as we found the element
        }
    }

    // Output the result
    if (found) {
        cout << "Element " << elementToSearch << " found at index: " << index << endl;
    } else {
        cout << elementToSearch << " not found in the arr[]" << endl;
    }

    return 0;
}