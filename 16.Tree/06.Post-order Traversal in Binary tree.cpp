#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform a **Postorder Traversal** of a binary tree using **recursion**.  
In **Postorder Traversal**, the order of visiting nodes is:
    Left Subtree -> Right Subtree -> Root

Given a binary tree, print or return the nodes in **postorder** recursively.

Example Tree:

                  1
                /   \
               2     3
              / \   / \
             4   5 7   8
                /     / \
               6     9  10

Expected Postorder Output: 4 6 5 2 7 9 10 8 3 1

================================================================================
Intuition / Approach:
================================================================================
1. Postorder is "Left -> Right -> Root".
2. Use recursion to traverse each subtree:
    a) Traverse the left subtree recursively.
    b) Traverse the right subtree recursively.
    c) Process the root node (print or add to result).
3. Base Case: If the current node is NULL, return immediately.
4. This ensures nodes are processed after their children.
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
// Recursive Postorder Traversal Function
// LEFT -> RIGHT -> ROOT
// ---------------------------
void postorder(Node* root) {
    if (root == NULL) return;   // Base case: empty node

    postorder(root->left);      // Step 1: Traverse left subtree
    postorder(root->right);     // Step 2: Traverse right subtree
    cout << root->data << " ";  // Step 3: Process root node
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

        Postorder Traversal Output: 4 6 5 2 7 9 10 8 3 1
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

    cout << "Postorder Traversal of Tree: ";
    postorder(root);
    cout << "\n";

    return 0;
}
