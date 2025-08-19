// Delete a Node in a Binary Search Tree (BST)
// -------------------------------------------
// Problem: Delete a node with a given value from a BST while maintaining
// the BST properties. After deletion, the tree must remain a valid BST.

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
// Helper Function: Find Last Right (Inorder Predecessor)
// ---------------------------
Node* findLastRight(Node* root) {
    while (root->right) root = root->right;
    return root;
}

// ---------------------------
// Helper Function: Handle Deletion Cases
// ---------------------------
Node* deleteHelper(Node* root) {
    // Case 1: No left child
    if (!root->left) return root->right;

    // Case 2: No right child
    if (!root->right) return root->left;

    // Case 3: Node has two children
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left); // Inorder predecessor
    lastRight->right = rightChild; // Attach right subtree
    return root->left; // Replace root with modified left subtree
}

// ---------------------------
// Recursive Deletion in BST
// ---------------------------
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr; // Base case: empty tree

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Found the node to delete
        return deleteHelper(root);
    }
    return root;
}
// Time Complexity: O(h) where h = height of BST (O(log N) for balanced BST)
// Space Complexity: O(h) due to recursion stack

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
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    cout << "Inorder Traversal of BST before deletion: ";
    inorder(root);
    cout << endl;

    int key = 3;
    root = deleteNode(root, key);

    cout << "Inorder Traversal of BST after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Deletion in BST depends on number of children of the node:
  1. No child → delete directly.
  2. One child → replace with the child.
  3. Two children → replace with inorder predecessor (largest in left subtree).
- Helper function ensures right subtree is attached properly.
- Recursive approach: O(h) time, O(h) recursion stack.
- BST property maintained after deletion.
================================================================================
*/
