// Search in a Binary Search Tree (BST)
// ------------------------------------
// Problem: Efficiently search for a given value in a BST and return the 
// node containing it. Returns nullptr if the value is not present.

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
// Iterative Search in BST
// ---------------------------
Node* searchBST(Node* root, int val) {
    while (root && root->data != val) {
        if (val < root->data)
            root = root->left;   // Move left if value is smaller
        else
            root = root->right;  // Move right if value is larger
    }
    return root;  // Will be nullptr if value not found
}
// Time Complexity: O(h) where h = height of BST (O(log N) for balanced BST)
// Space Complexity: O(1) iterative

// ---------------------------
// Recursive Search in BST
// ---------------------------
Node* searchBSTRecursive(Node* root, int val) {
    if (!root || root->data == val) return root;

    if (val < root->data)
        return searchBSTRecursive(root->left, val);
    else
        return searchBSTRecursive(root->right, val);
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

    int searchVal = 10;
    Node* result = searchBST(root, searchVal);
    if (result)
        cout << "Value " << searchVal << " found at node with address: " << result << endl;
    else
        cout << "Value " << searchVal << " not found in BST." << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- BST property: left < root < right.
- Iterative search avoids recursion stack, space O(1).
- Recursive search is more concise, space O(h) due to recursion.
- Search time depends on tree height: O(log N) for balanced BST, O(N) for skewed.
- Returns the actual node pointer if found; nullptr if not found.
================================================================================
*/
