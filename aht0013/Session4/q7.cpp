#include <iostream>
#include <string>
using namespace std;

void processArrays(float** floatArr, int rows, int cols, string** stringArr) {
    cout << "Enter float values:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> floatArr[i][j];
        }
    }

    cout << "Enter string values:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> stringArr[i][j];
        }
    }

    cout << "\nFloat Array:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << floatArr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nString Array:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << stringArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    float** floatArr = new float*[rows];
    for(int i = 0; i < rows; i++) {
        floatArr[i] = new float[cols];
    }

    string** stringArr = new string*[rows];
    for(int i = 0; i < rows; i++) {
        stringArr[i] = new string[cols];
    }

    processArrays(floatArr, rows, cols, stringArr);

    for(int i = 0; i < rows; i++) {
        delete[] floatArr[i];
        delete[] stringArr[i];
    }
    delete[] floatArr;
    delete[] stringArr;

    return 0;
}