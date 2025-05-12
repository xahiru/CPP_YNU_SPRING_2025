#include <iostream>
#include <string>
using namespace std;

void inputAndDisplayArrays(int rows, int cols) {
    float** floatArr = new float*[rows];
    for (int i = 0; i < rows; i++) {
        floatArr[i] = new float[cols];
    }

    string** stringArr = new string*[rows];
    for (int i = 0; i < rows; i++) {
        stringArr[i] = new string[cols];
    }

    cout << "Enter values for the floating-point array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter floatArr[" << i << "][" << j << "]: ";
            cin >> floatArr[i][j];
        }
    }

    cout << "\nEnter values for the string array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter stringArr[" << i << "][" << j << "]: ";
            cin >> stringArr[i][j];
        }
    }

    cout << "\nDisplaying the floating-point array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << floatArr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDisplaying the string array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << stringArr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] floatArr[i];
    }
    delete[] floatArr;

    for (int i = 0; i < rows; i++) {
        delete[] stringArr[i];
    }
    delete[] stringArr;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the arrays: ";
    cin >> rows >> cols;

    inputAndDisplayArrays(rows, cols);

    return 0;
}
