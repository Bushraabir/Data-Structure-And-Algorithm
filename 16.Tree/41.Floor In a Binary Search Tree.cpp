// Floor in a Binary Search Tree (BST)
// ----------------------------------
// Problem: Find the largest node in a BST whose value is smaller than or equal 
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
// Iterative Floor in BST
// ---------------------------
Node* floorBST(Node* root, int key) {
    Node* floorNode = nullptr;
    while (root) {
        if (root->data == key) {
            floorNode = root;  // Exact match
            break;
        } else if (root->data > key) {
            root = root->left;  // Move left for smaller values
        } else {
            floorNode = root;   // Potential floor, move right to find larger <= key
            root = root->right;
        }
    }
    return floorNode;
}
// Time Complexity: O(h) where h = height of BST (O(log N) for balanced BST)
// Space Complexity: O(1) iterative

// ---------------------------
// Recursive Floor in BST
// ---------------------------
Node* floorBSTRecursive(Node* root, int key) {
    if (!root) return nullptr;

    if (root->data == key) return root;
    else if (root->data > key) return floorBSTRecursive(root->left, key);
    else {
        Node* rightFloor = floorBSTRecursive(root->right, key);
        return rightFloor ? rightFloor : root;
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

    int key = 9;
    Node* floorNode = floorBST(root, key);
    if (floorNode)
        cout << "Floor of " << key << " in BST is: " << floorNode->data << endl;
    else
        cout << "Floor does not exist for " << key << " in BST." << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Floor: largest value <= key in BST.
- Iterative approach: O(h) time, O(1) space.
- Recursive approach: O(h) time, O(h) recursion stack.
- BST property allows efficient traversal to find floor.
- If no node <= key exists, returns nullptr.
================================================================================
*/
