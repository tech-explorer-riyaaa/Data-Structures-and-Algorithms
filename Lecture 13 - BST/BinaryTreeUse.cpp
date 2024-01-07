#include <iostream>
#include <climits>
#include "BinaryTreeNode.h" // - already included in below file
// or remove it from below file - not best solution (both)
#include <queue>
#include "BinarySearchTree.h"
using namespace std; // its position matters as dusri files k cout ko bhi ye chaiye

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "enter root data: " << endl;
    cin >> rootData;
    if (rootData == -1) { // although not needed here, just as a convention
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter left child of " << front -> data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front -> left = child;
            pendingNodes.push(child);
        }
        cout << "enter right child of " << front -> data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front -> right = child;
            pendingNodes.push(child); //enqueue
        }
    }
    return root;
}

int maximum(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MIN; // base case
    }
    return max((root -> data), max(maximum(root -> left), maximum(root -> right)));
}

int minimum(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MAX; // base case
    } 
    return min(root -> data, min(minimum(root -> left), minimum(root -> right)));
}

bool isBST(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return true; // base case
    }
    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);
    bool output = (root -> data > leftMax) && (root -> data <= rightMin) && isBST(root -> left) && isBST(root -> right);
    // do recursive calls - har node p jayenge
    // at each node how much work are you doing :
    // maximum() and minimum() - firse har node p jaa rhe hai
    return output;
}

// Check BST-2
class IsBSTReturn {
    public:
    bool isBST;
    int maximum;
    int minimum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
    if (root == NULL) { // base case
        IsBSTReturn output; // object
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput = isBST2(root -> right);
    IsBSTReturn rightOutput = isBST2(root -> right);
    int minimum = min(root -> data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root -> data > leftOutput.maximum) && (root -> data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    return output;
}

// Check BST-3
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if (root == NULL) {
        return true; // base case
    }
    if (root -> data < min || root -> data > max) {
        return false;
    }
    bool isLeftOk = isBST3(root -> left, min, root -> data - 1);
    bool isRightOk = isBST3(root -> right, root -> data, max);
    return isLeftOk && isRightOk;
}

// path from root to node
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
    if (root == NULL) { // base case
        return NULL; // nahi mila data
    }
    if (root -> data == data) {
        vector<int>* output = new vector<int>(); // dynamically created
        output -> push_back(root -> data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root -> left, data);
    if (leftOutput != NULL) {
        leftOutput -> push_back(root -> data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root -> right, data);
    if (rightOutput != NULL) {
        rightOutput -> push_back(root -> data);
        return rightOutput;
    } else {
        return NULL; // root p nahi mila, left mei nahi mila, right mei nahi mila.
    }
}

int main() {
    /*
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // cout << isBST(root) << endl;
    // cout << isBST3(root) << endl;
    vector<int>* output = getRootToNodePath(root, 8);
    for(int i = 0; i < output -> size(); i++) {
        cout << output -> at(i) << endl;
    }
    delete output; // upar function mei vector ko humne dynamically allocate kara tha taaki woh survive kare 
    */

   BST b;
   b.insert(10);
   b.insert(5);
   b.insert(20);
   b.insert(7);
   b.insert(3);
   b.insert(15);
   b.printTree();
   b.deleteData(10);
   b.deleteData(100);
   b.printTree();
}