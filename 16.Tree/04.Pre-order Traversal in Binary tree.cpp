#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform a **Preorder Traversal** of a binary tree using **recursion**.  
In **Preorder Traversal**, the order of visiting nodes is:
    Root -> Left Subtree -> Right Subtree

Given a binary tree, print or return the nodes in **preorder** recursively.

Example Tree:

                 1
                / \
               2   3
              / \   \
             4   5   8
                /   / \
               6   9  10
              /
             7

Expected Preorder Output: 1 2 4 5 6 3 7 8 9 10

================================================================================
Intuition / Approach:
================================================================================
1. Preorder follows "Root -> Left -> Right".
2. Use recursion to traverse the tree:
    a) Process the root node (print or add to result) first.
    b) Traverse the left subtree recursively.
    c) Traverse the right subtree recursively.
3. Base Case: If the current node is NULL, return immediately.
4. This ensures that each node is processed **before** its children, following the preorder rule.
5. Continue until all nodes are visited.

Time Complexity: O(N)
- Each node is visited exactly **once**.
- There is a single recursion call per node.

Space Complexity: O(H)
- H is the height of the tree.
- The recursion stack can hold at most H nodes at a time.
- Best case (balanced tree): O(log N)
- Worst case (skewed tree): O(N)

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
// Recursive Preorder Traversal Function
// ROOT -> LEFT -> RIGHT
// ---------------------------
void preorder(Node* root) {
    if (root == NULL) return;      // Base case: empty node

    cout << root->data << " ";     // Step 1: Process root
    preorder(root->left);          // Step 2: Traverse left subtree
    preorder(root->right);         // Step 3: Traverse right subtree
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the following Binary Tree for demo:

                 1
                / \
               2   3
              / \   \
             4   5   8
                /   / \
               6   9  10
              /
             7

        Preorder Traversal Output: 1 2 4 5 6 3 7 8 9 10
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

    cout << "Preorder Traversal of Tree: ";
    preorder(root);
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited exactly once.
- Each visit performs constant-time operations (printing and recursion calls).
- Total = O(N), where N is the number of nodes in the tree.

Space Complexity: O(H)
- H = height of the tree.
- The recursion stack stores the nodes along the current path from root to leaf.
- Best case (perfectly balanced tree): H = log2(N) → Space = O(log N)
- Worst case (completely skewed tree): H = N → Space = O(N)
- No additional data structures are used.
================================================================================
*/
