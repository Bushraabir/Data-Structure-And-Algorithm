#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform an **Inorder Traversal** of a binary tree using **recursion**.  
In **Inorder Traversal**, the order of visiting nodes is:
    Left Subtree -> Root -> Right

Given a binary tree, print or return the nodes in **inorder** recursively.

Example Tree:

                  1
                /   \
               2     3
              / \   / \
             4   5 7   8
                /     / \
               6     9  10

Expected Inorder Output: 4 2 6 5 1 7 3 9 8 10

================================================================================
Intuition / Approach:
================================================================================
1. Inorder is "Left -> Root -> Right".
2. Use recursion to traverse each subtree:
    a) Traverse the left subtree recursively.
    b) Process the root node (print or add to result).
    c) Traverse the right subtree recursively.
3. Base Case: If the current node is NULL, return immediately.
4. This ensures nodes are processed in the correct inorder sequence.
5. Continue until all nodes are visited.

Time Complexity: O(N), as each node is visited exactly once.
Space Complexity: O(H), where H is the height of the tree (recursion stack usage).
================================================================================
*/

// ---------------------------
// Definition of a Node in Binary Tree
// ---------------------------
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor for easy node creation
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------------------------
// Recursive Inorder Traversal Function
// LEFT -> ROOT -> RIGHT
// ---------------------------
void inorder(Node* root) {
    if (root == NULL) return;    // Base case: empty node

    inorder(root->left);         // Step 1: Traverse left subtree
    cout << root->data << " ";   // Step 2: Process root node
    inorder(root->right);        // Step 3: Traverse right subtree
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the following Binary Tree for demo:

                  1
                /   \
               2     3
              / \   / \
             4   5 7   8
                /     / \
               6     9  10

        Inorder Traversal Output: 4 2 6 5 1 7 3 9 8 10
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Inorder Traversal of Tree: ";
    inorder(root);
    cout << "\n";

    return 0;
}
