#include <iostream>
#include <string>

int main() {
    // Float array (2x2)
    int rF = 2, cF = 2;
    float** fArr = new float*[rF];
    for (int i = 0; i < rF; ++i) {
        fArr[i] = new float[cF];
        for (int j = 0; j < cF; ++j) fArr[i][j] = (i + 1) * (j + 0.5f);
    }
    std::cout << "Floats:\n";
    for (int i = 0; i < rF; ++i) {
        for (int j = 0; j < cF; ++j) std::cout << fArr[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < rF; ++i) delete[] fArr[i];
    delete[] fArr;

    // String array (2x2)
    int rS = 2, cS = 2;
    std::string** sArr = new std::string*[rS];
    for (int i = 0; i < rS; ++i) {
        sArr[i] = new std::string[cS];
        for (int j = 0; j < cS; ++j) sArr[i][j] = "S" + std::to_string(i) + std::to_string(j);
    }
    std::cout << "\nStrings:\n";
    for (int i = 0; i < rS; ++i) {
        for (int j = 0; j < cS; ++j) std::cout << sArr[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < rS; ++i) delete[] sArr[i];
    delete[] sArr;

    return 0;
}