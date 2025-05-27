#include <iostream>
using namespace std;

struct Node {
    bool isLeaf;
    union {
        double data;
        struct {
            Node* left;
            Node* right;
        } children;
    };
};

int main() {
    Node leaf = {true, .data = 3.14};
    Node internal = {false, .children = {nullptr, nullptr}};
    return 0;
}