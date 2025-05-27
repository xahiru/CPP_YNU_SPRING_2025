#include <iostream>
using namespace std;

struct Area {
    int side;
    int len;
    int wid;
};

void find_area(int side, int len, int wid) {
    Area a;
    a.side = side;
    a.len = len;
    a.wid = wid;
    cout << (a.side * a.side) << " " << (a.len * a.wid) << endl;
}

int main() {
    find_area(25, 40, 60);
    return 0;
}
