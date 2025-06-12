#include <iostream>
using namespace std;

struct Area {
    int side, len, wid;
};

void find_area(int side, int len, int wid) {
    cout << side * side << " " << len * wid;
}

int main() {
    Area a = {25, 40, 60};
    find_area(a.side, a.len, a.wid);
    return 0;
}