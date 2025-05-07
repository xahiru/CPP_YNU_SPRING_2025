#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows = 2;
    int cols = 3;

    // Dynamically allocate 2D float array
    float** floatArray = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        floatArray[i] = new float[cols];
    }

    // Initialize float array
    float value = 1.1f;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            floatArray[i][j] = value;
            value += 1.1f;
        }
    }

    // Display float array
    cout << "2D Float Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << floatArray[i][j] << "\t";
        }
        cout << endl;
    }

    string** stringArray = new string*[rows];
    for (int i = 0; i < rows; ++i) {
        stringArray[i] = new string[cols];
    }

    string words[2][3] = {
        {"Apple", "Banana", "Cherry"},
        {"Dog", "Elephant", "Fox"}
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            stringArray[i][j] = words[i][j];
        }
    }

    cout << "\n2D String Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << stringArray[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] floatArray[i];
    }
    delete[] floatArray;

    for (int i = 0; i < rows; ++i) {
        delete[] stringArray[i];
    }
    delete[] stringArray;

    return 0;
}
