#include <iostream>
using namespace std;

int main() {
    int rows = 2, cols = 3;

    float** floatArray = new float*[rows];
    for (int i = 0; i < rows; i++) {
        floatArray[i] = new float[cols];
    }

    float val = 1.1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            floatArray[i][j] = val;
            val += 1.1;
        }
    }

    cout << "Float Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << floatArray[i][j] << " ";
        }
        cout << endl;
    }

    string** stringArray = new string*[rows];
    for (int i = 0; i < rows; i++) {
        stringArray[i] = new string[cols];
    }

    string words[2][3] = {{"apple", "banana", "cherry"}, {"dog", "elephant", "fish"}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            stringArray[i][j] = words[i][j];
        }
    }

    cout << "\nString Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << stringArray[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] floatArray[i];
        delete[] stringArray[i];
    }
    delete[] floatArray;
    delete[] stringArray;

    return 0;
}