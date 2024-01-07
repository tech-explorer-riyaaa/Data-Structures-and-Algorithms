#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* TakeInputLevelWise() {
  int rootData;
  cout << "Enter root data : " << endl;
  cin >> rootData;
  TreeNode<int>* root = new TreeNode<int>(rootData);

  queue<TreeNode<int>*> pendingNodes; // pending nodes

  pendingNodes.push(root);
  while (pendingNodes.size() != 0) {
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout << "enter num of children of " << front -> data << " : "  << endl;
    int numChild;
    cin >> numChild;
    for (int i = 0; i < numChild; i++) {
      int childData;
      cout << "enter " << i << "th child of " << front -> data << " : " << endl;
      cin >> childData;
      // TreeNode<int> child(childData); // static allocation // major issue - func khtm hone k baad node udd jayegi.. 
      // agli iteration p hi memeory jaa chuki hogi
      // this is a local variable
      // agli iteration mei pop krke - ye queue se bahar aa paaye - usse milega address
      //  pr uss address p jo bhi tha wo toh jaa chuka hoga
      TreeNode<int>* child = new TreeNode<int>(childData); 
      // we want this memory to survive
      front -> children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

TreeNode<int>* takeInput() {
    // abhi NULL tree ka case handle nahi kiya hai
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "enter num of children of " << rootData <<" : " << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    if (root == NULL) { // edge case
        cout << "empty tree" << endl;
        return;
    }
      cout << root -> data << ": ";
      for(int i = 0; i < root-> children.size(); i++) {
        cout << root -> children[i]-> data << ", ";
      }
      cout << endl;
      for (int i = 0; i < root -> children.size(); i++) {
        printTree(root -> children[i]); // recursion
      }
}

int numNodes(TreeNode<int>* root) {
  if (root == NULL) {
    return 0; // to handle edge case
  }
  int ans = 1;
  for (int i = 0; i < root -> children.size(); i++) {
    ans += numNodes(root -> children[i]);
  }
  return ans; 
}

void printAtLevelK(TreeNode<int>* root, int k) {

  if (root == NULL) {
    return; // to handle edge case
  }
  if (k == 0) {
    cout << root -> data << endl;
    return;
  }
  for (int i = 0; i < root -> children.size(); i++) {
    printAtLevelK(root -> children[i], k - 1);
  }
}

// Pre-order Traversal
void preorder(TreeNode<int>* root) {
  if(root == NULL) {
    return; // edge case
  }
  cout << root -> data << " ";
  for(int i = 0; i < root -> children.size(); i++){
    preorder(root -> children[i]);
  }
} 

void deleteTree(TreeNode<int>* root) {
  for(int i = 0; i < root -> children.size(); i++) {
    deleteTree(root -> children[i]);
  }
  delete root;
  // using post-order traversal
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 1 9 0 
// baar baar tree add krne ki zarurat nahi
// yahi se uthao copy krke daaldo

int main() {
    
    // TreeNode<int>* root = takeInput();
    TreeNode<int>* root = TakeInputLevelWise();
    printTree(root);
    cout << "num : " << numNodes(root) << endl;
    cout << "Level 2 : " << endl;
    printAtLevelK(root, 2);
    cout << "pre-order : " << " ";
    preorder(root);

    // TO DO - delete the tree
    // deleteTree(root); or
    delete(root); // modified the destructor - used recursion inside destructor
    // deleted the whole tree
}