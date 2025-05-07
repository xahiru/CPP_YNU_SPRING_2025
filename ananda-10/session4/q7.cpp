#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows = 2, cols = 3;

    float** floatArray = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        floatArray[i] = new float[cols];
    }

    float value = 1.1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            floatArray[i][j] = value;
            value += 1.1f;
        }
    }

    string** strArray = new string*[rows];
    for (int i = 0; i < rows; ++i) {
        strArray[i] = new string[cols];
    }

    strArray[0][0] = "A"; strArray[0][1] = "B"; strArray[0][2] = "C";
    strArray[1][0] = "D"; strArray[1][1] = "E"; strArray[1][2] = "F";

    cout << "Float 2D Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << floatArray[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nString 2D Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << strArray[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < rows; ++i) {
        delete[] floatArray[i];
        delete[] strArray[i];
    }
    delete[] floatArray;
    delete[] strArray;

    return 0;
}

