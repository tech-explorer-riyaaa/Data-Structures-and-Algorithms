#include <iostream>
using namespace std; // for cout to run
// #include "BinaryTreeNode.h"
class BST {
    BinaryTreeNode<int>* root;
    public :

    BST() {
        root = NULL;
    }

    ~BST() {
        delete root; // recursive destructor
        // root ko bolenge del kr... sb kuch apne aap del ho jayega
    }

    private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
        if (node == NULL) {
            return NULL;
        }
        if (data > node -> data) {
            node -> right = deleteData(data, node -> right);
            return node; // isne mujhe warning nahi di thi, pr video mei di thi
        } else if (data < node -> data) {
            node -> left = deleteData(data, node -> left);
            return node;
        } else {
            if (node -> left == NULL && node -> right == NULL) {
                delete node;
                return NULL;
            } else if (node -> left == NULL) {
                BinaryTreeNode<int>* temp = node -> right;
                node -> right = NULL; // node apne right side wale ko del krke nahi jayega
                delete node;
                return temp;
            } else if (node -> right == NULL) {
                BinaryTreeNode<int>* temp = node -> left;
                node -> left = NULL; // node apne left side wale ko del krke nahi jayega
                delete node;
                return temp;
            } else {
                // right side ka min will be my replacement - left mei jaate rhenge
                BinaryTreeNode<int>* minNode = node -> right;
                while (minNode -> left != NULL) {
                    minNode =  minNode -> left;
                }
                int rightMin = minNode -> data;
                node -> data = rightMin;
                node -> right = deleteData(rightMin, node -> right); // this might change the node's right - right mei ek hi node hai     
                return node; // root is still the same node     
            }
        }
    }

    public:
    void deleteData(int data) {
        this -> root = deleteData(data, root);
    }

    private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node) {
        if (node == NULL) {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data < node -> data) {
            node -> left = insert(data, node -> left);
        } else {
            node -> right = insert(data, node -> right);
        }
        return node;
    }

    public:
    void insert(int data) {
        this -> root = insert(data, this -> root);
    }

    private :
    bool hasData(int data, BinaryTreeNode<int>* node) { // ise object ki root se lena dena nahi hai
        if (node == NULL) {
            return false; // base case
        }
        if (node -> data == data) {
            return true;
        } else if (data < node -> data) {
            return hasData(data, node -> left);
        } else {
            return hasData(data, root -> right);
        }
    }

    public:
    bool hasData(int data) { // object ki root p kaam krta hai
        return hasData(data, root); 
    }

    private:
    // needed for recursive call
    void printTree(BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return;
        }
        cout << root -> data << ":";
        if (root -> left != NULL) {
            cout << "L" << root -> left -> data;
        }
        if (root -> right != NULL) {
            cout << "R" << root -> right -> data;
        }
        cout << endl;
        printTree(root -> left);
        printTree(root -> right);
    }

    public:
    void printTree() {
        printTree(root);
    }

};