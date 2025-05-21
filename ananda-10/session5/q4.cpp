#include <iostream>
#include <cstring> 
#include <cctype>  
using namespace std;

void capitalizeFirstLetter(char arr[][20], int size) {
    cout << "Capitalize the first character of each vector element:\n";
    for (int i = 0; i < size; ++i) {
        if (strlen(arr[i]) > 0) { 
            arr[i][0] = toupper(arr[i][0]); 
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    char arr[5][20] = {"red", "green", "black", "white", "pink"};

    cout << "Original Vector elements:\n";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    capitalizeFirstLetter(arr, 5);

    return 0;
}
