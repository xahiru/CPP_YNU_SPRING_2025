#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows = 2, cols = 3;
    float **floatArray = new float*[rows];
    string **strArray = new string*[rows];

    for (int i = 0; i < rows; i++) {
        floatArray[i] = new float[cols];
        strArray[i] = new string[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            floatArray[i][j] = (i + 1) * (j + 1);
            strArray[i][j] = "Row " + to_string(i) + ", Col " + to_string(j);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << floatArray[i][j] << " " << strArray[i][j] << endl;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] floatArray[i];
        delete[] strArray[i];
    }
    delete[] floatArray;
    delete[] strArray;
    return 0;
}
