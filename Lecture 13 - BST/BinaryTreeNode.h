#include <iostream>
template <typename T>
class BinaryTreeNode {

    public :
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    // Constructor
    BinaryTreeNode(T data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

    // Recursive Destructor
    ~BinaryTreeNode() {
        // delete NULL - ignore kr deta h, kuch issue hota nahi hai.
        delete left;
        delete right;
    }
};