#include <iostream>
#include "TreeNode.h" // using local file
using namespace std;

int main() {
    // TreeNode<int>* root = new TreeNode<int>();
    // root -> data = 10; 
    // to avoid these two steps

    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root -> children.push_back(node1);
    root -> children.push_back(node2);
    // in do steps se 1 se 2 and 3 ka connection bann gya h

    // TO-DO - delete the tree
}