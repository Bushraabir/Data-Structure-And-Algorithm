// Validate a Binary Search Tree (BST)
// -----------------------------------
// Problem: Given a binary tree, check whether it is a valid BST or not.
// A BST has the property that for every node:
//    - All values in the left subtree are smaller than the node.
//    - All values in the right subtree are greater than the node.
//    - This property must hold true recursively for all subtrees.

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Definition of a Tree Node
// ---------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ---------------------------
// Helper Function: Validate BST
// ---------------------------
bool validate(Node* root, long minVal, long maxVal) {
    if (!root) return true;

    if (root->data <= minVal || root->data >= maxVal) return false;

    // Left subtree: max value becomes root->data
    // Right subtree: min value becomes root->data
    return validate(root->left, minVal, root->data) &&
           validate(root->right, root->data, maxVal);
}

bool isValidBST(Node* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}
// Time Complexity: O(N) since every node is visited once
// Space Complexity: O(H) recursion stack, where H = height of tree

// ---------------------------
// Utility: Inorder Traversal
// ---------------------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Node* root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(10);
    root->right->left = new Node(7);

    cout << "Inorder Traversal of Tree: ";
    inorder(root);
    cout << endl;

    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Naive local checks (left < root < right) are NOT sufficient.
- A node must also satisfy the constraints passed down from its ancestors.
- Use DFS traversal with range validation:
  -> Root has range (-∞, +∞).
  -> Left child range: (min, root->val).
  -> Right child range: (root->val, max).
- If any node violates its range → Not a BST.
- Time Complexity: O(N) (visit each node once).
- Space Complexity: O(H) recursion stack.
================================================================================
*/
