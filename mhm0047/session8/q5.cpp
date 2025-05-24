#include <iostream>
using namespace std;

int main() {
    struct Area {
        int side, len, wid;
    };

    Area a = {25, 40, 60};
    int square = a.side * a.side;
    int rectangle = a.len * a.wid;

    cout << square << " " << rectangle;
    return 0;
}
