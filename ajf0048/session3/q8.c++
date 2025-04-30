#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[][100] = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    int size = sizeof(arr) / sizeof(arr[0]);
    int first = 0, second = 0, third = 0;

    for (int i = 1; i < size; i++) {
        if (strlen(arr[i]) > strlen(arr[first])) {
            third = second;
            second = first;
            first = i;
        } else if (strlen(arr[i]) > strlen(arr[second])) {
            third = second;
            second = i;
        } else if (strlen(arr[i]) > strlen(arr[third])) {
            third = i;
        }
    }

    cout << "Third highest length string: " << arr[third] << endl;
    return 0;
}
