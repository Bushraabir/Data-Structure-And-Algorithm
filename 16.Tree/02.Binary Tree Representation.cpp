#include <bits/stdc++.h>
using namespace std;

/*
Build a simple binary tree and verify it using a **Preorder Traversal** (Root → Left → Right).

Given a binary tree, implement:
1. Node structure using pointers.
2. Preorder traversal function (recursive).

Example Tree:

            1
           / \
          2   3
         / \
        4   5

Expected Preorder Output: 1 2 4 5 3


Intuition / Approach:
- Use a struct to define a tree node with data and pointers to left and right children.
- Manually create nodes and link them to form the tree. 
1. Each node contains:
    - int data
    - Node* left
    - Node* right
2. Build tree using "new" keyword:
    a) Create root
    b) Attach children using pointers
3. Preorder Traversal:
    a) Visit root
    b) Traverse left subtree recursively
    c) Traverse right subtree recursively

Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(H)
- H = height of the tree
- Recursion stack can hold up to H nodes.

*/

// ---------------------------
// Definition of a Node in Binary Tree
// ---------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------------------------
// Preorder Traversal (Root -> Left -> Right)
// ---------------------------
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the Binary Tree:

            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal of Tree: ";
    preorder(root);
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Preorder Traversal:
- Time Complexity: O(N)
  - Each node is visited exactly once.

- Space Complexity: O(H)
  - Recursion stack stores nodes along current path from root to leaf.
  - Best case (balanced tree): O(log N)
  - Worst case (skewed tree): O(N)
================================================================================
*/
