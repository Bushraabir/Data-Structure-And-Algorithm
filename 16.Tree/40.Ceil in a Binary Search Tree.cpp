// Ceil in a Binary Search Tree (BST)
// ----------------------------------
// Problem: Find the smallest node in a BST whose value is greater than or equal 
// to a given key. If no such node exists, return nullptr.

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
// Iterative Ceil in BST
// ---------------------------
Node* ceilBST(Node* root, int key) {
    Node* ceilNode = nullptr;
    while (root) {
        if (root->data == key) {
            ceilNode = root;
            break;  // Exact match found
        } else if (key < root->data) {
            ceilNode = root;   // Possible ceil, move left to find smaller one
            root = root->left;
        } else {
            root = root->right;  // Move right if key is larger
        }
    }
    return ceilNode;
}
// Time Complexity: O(h) where h = height of BST (O(log N) for balanced BST)
// Space Complexity: O(1) iterative

// ---------------------------
// Recursive Ceil in BST
// ---------------------------
Node* ceilBSTRecursive(Node* root, int key) {
    if (!root) return nullptr;

    if (root->data == key) return root;
    else if (key > root->data) return ceilBSTRecursive(root->right, key);
    else {
        Node* leftCeil = ceilBSTRecursive(root->left, key);
        return leftCeil ? leftCeil : root;
    }
}
// Time Complexity: O(h)
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
    Node* root = nullptr;

    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int val : values) {
        if (!root) root = new Node(val);
        else {
            Node* curr = root;
            while (true) {
                if (val < curr->data) {
                    if (!curr->left) { curr->left = new Node(val); break; }
                    curr = curr->left;
                } else {
                    if (!curr->right) { curr->right = new Node(val); break; }
                    curr = curr->right;
                }
            }
        }
    }

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int key = 5;
    Node* ceilNode = ceilBST(root, key);
    if (ceilNode)
        cout << "Ceil of " << key << " in BST is: " << ceilNode->data << endl;
    else
        cout << "Ceil does not exist for " << key << " in BST." << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Ceil: smallest value >= key in BST.
- Iterative approach: O(h) time, O(1) space.
- Recursive approach: O(h) time, O(h) recursion stack.
- BST property allows moving left/right efficiently to find ceil.
- If no node >= key exists, returns nullptr.
================================================================================
*/
