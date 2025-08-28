// Insert a Node in a Binary Search Tree (BST)
// -------------------------------------------
// Problem: Insert a new node with a given value into a BST while maintaining
// the BST properties. The new node is always inserted at a leaf position.

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
// Iterative Insertion in BST
// ---------------------------
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val); // Base case: empty tree

    Node* curr = root;
    while (true) {
        if (val < curr->data) {
            if (!curr->left) { // Found insertion point
                curr->left = new Node(val);
                break;
            }
            curr = curr->left;
        } else { // val > curr->data
            if (!curr->right) { // Found insertion point
                curr->right = new Node(val);
                break;
            }
            curr = curr->right;
        }
    }
    return root;
}
// Time Complexity: O(h) where h = height of BST (O(log N) for balanced BST)
// Space Complexity: O(1) iterative

// ---------------------------
// Recursive Insertion in BST
// ---------------------------
Node* insertBSTRecursive(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insertBSTRecursive(root->left, val);
    else // val > root->data
        root->right = insertBSTRecursive(root->right, val);

    return root;
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

    vector<int> values = {6, 3, 8, 1, 4, 7};
    for (int val : values)
        root = insertBST(root, val); // Using iterative insertion

    cout << "Inorder Traversal of BST before insertion: ";
    inorder(root);
    cout << endl;

    int newVal = 5;
    root = insertBST(root, newVal); // Insert new node

    cout << "Inorder Traversal of BST after inserting " << newVal << ": ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- BST insertion: traverse as if searching for value, insert at leaf.
- Iterative approach: O(h) time, O(1) space.
- Recursive approach: O(h) time, O(h) recursion stack.
- BST property maintained: left < root < right.
- New value is always unique in BST; duplicates are ignored in this example.
================================================================================
*/
