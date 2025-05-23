#include <iostream>

struct NODE {
    double data;
    union {
        NODE* left;
        NODE* right;
    };
};

int main() {
    
    NODE* root = new NODE{3.14, {nullptr, nullptr}};
    NODE* leftChild = new NODE{2.71, {nullptr, nullptr}};
    NODE* rightChild = new NODE{1.61, {nullptr, nullptr}};

    root->left = leftChild;
    root->right = rightChild;

    std::cout << "Root data: " << root->data << std::endl;
    std::cout << "Left child data: " << leftChild->data << std::endl;
    std::cout << "Right child data: " << rightChild->data << std::endl;

    delete leftChild;
    delete rightChild;
    delete root;

    return 0;
}
