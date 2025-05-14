#include <iostream>
using namespace std;

int* createSquaresArray(int size) {
    int* arr = new int[size];
    for (int count = 0; count < size; ++count) {
        arr[count] = (count + 1) * (count + 1);
    }
    return arr;
}

void printArray(const int* arr, int size) {
    cout << "Squares:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    int numElements;
    
    cout << "How many squares to generate? ";
    cin >> numElements;
    
    int* squareNumbers = createSquaresArray(numElements);
    printArray(squareNumbers, numElements);
    
    delete[] squareNumbers;
    return 0;
}