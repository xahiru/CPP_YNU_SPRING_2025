#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> capitalizeFirstLetter(vector<string> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (!vec[i].empty()) {
            vec[i][0] = toupper(vec[i][0]);
        }
    }
    return vec;
}

int main() {
    vector<string> colors = {"red", "green", "black", "white", "Pink"};

    cout << "Original Vector elements:\n";
    for (const auto& color : colors) {
        cout << color << " ";
    }
    cout << "\n";

    vector<string> capitalizedColors = capitalizeFirstLetter(colors);

    cout << "Capitalize the first character of each vector element:\n";
    for (const auto& color : capitalizedColors) {
        cout << color << " ";
    }
    cout << "\n";

    return 0;
}
