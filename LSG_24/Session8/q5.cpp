#include <iostream>
using namespace std;

struct Area {
    int side;
    int len;
    int wid;
};

void find_area(int side, int len, int wid) {
    cout << side * side << " " << len * wid << endl;
}

int main() {
    Area a;
    a.side = 25;
    a.len = 40;
    a.wid = 60;
    
    find_area(a.side, a.len, a.wid);
    return 0;
}