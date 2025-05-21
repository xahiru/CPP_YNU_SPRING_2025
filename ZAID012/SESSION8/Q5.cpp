#include <iostream>
using namespace std;

struct Area {
    int side;
    int len;
    int wid;
};

void findArea(Area area) {
    int squareArea = area.side * area.side;
    int rectangleArea = area.len * area.wid;
    cout << "Square Area: " << squareArea << ", Rectangle Area: " << rectangleArea << endl;
}

int main() {
    Area area = {25, 40, 60};
    findArea(area);
    return 0;
}
