#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    int rowsFloat = 3;
    int colsFloat = 4;

    float **floatArray = new float*[rowsFloat]; 
    for (int i = 0; i < rowsFloat; i++) {
        floatArray[i] = new float[colsFloat]; 
    }

    for (int i = 0; i < rowsFloat; i++) {
        for (int j = 0; j < colsFloat; j++) {
            floatArray[i][j] = (i + 1) * (j + 1) * 1.5; 
        }
    }

    int rowsStr = 3;
    int colsStr = 20; 

    char **strArray = new char*[rowsStr]; 
    for (int i = 0; i < rowsStr; i++) {
        strArray[i] = new char[colsStr]; 
    }

    strcpy(strArray[0], "Row 1");
    strcpy(strArray[1], "Row 2");
    strcpy(strArray[2], "Row 3");

    cout << "Floating-point Array:" << endl;
    for (int i = 0; i < rowsFloat; i++) {
        for (int j = 0; j < colsFloat; j++) {
            cout << floatArray[i][j] << " "; 
        }
        cout << endl;
    }

    cout << "String Array:" << endl;
    for (int i = 0; i < rowsStr; i++) {
        cout << strArray[i] << endl; 
    }

    for (int i = 0; i < rowsFloat; i++) {
        delete[] floatArray[i]; 
    }
    delete[] floatArray; 

    for (int i = 0; i < rowsStr; i++) {
        delete[] strArray[i]; 
    }
    delete[] strArray; 

    return 0;
}