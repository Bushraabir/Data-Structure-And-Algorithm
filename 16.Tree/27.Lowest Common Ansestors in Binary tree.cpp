#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree.

Definition:
- The Lowest Common Ancestor (LCA) of two given nodes P and Q is defined as 
  the lowest (deepest) node in the tree that has both P and Q as descendants.
- A node can be a descendant of itself.

Example:

Tree:
            1
           / \
          2   3
         / \   \
        4   5   6
             \
              7

Queries:
- LCA(4, 7) = 2
- LCA(5, 6) = 1
- LCA(2, 4) = 2
- LCA(8, 7) = 3   (if 8 is added as right child of 3)

================================================================================
Intuition / Approach:
================================================================================
Optimized Recursive Approach (Single Traversal):

1. Start from the root and check for three base cases:
   - If current node == NULL → return NULL
   - If current node == P or current node == Q → return current node

2. Recurse for left and right children:
   - left = LCA(root->left, P, Q)
   - right = LCA(root->right, P, Q)

3. Process results:
   - If both left and right are not NULL → current node is LCA
   - If only left is not NULL → return left
   - If only right is not NULL → return right
   - If both NULL → return NULL

4. This naturally handles ancestor-descendant cases:
   - If one node is ancestor of the other, the ancestor will be returned.

================================================================================
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
        left = right = nullptr;
    }
};

// ---------------------------
// Recursive Function to Find LCA
// ---------------------------
Node* LCA(Node* root, int p, int q) {
    if (!root) return nullptr;

    // Step 1: If root matches one of the targets, return root
    if (root->data == p || root->data == q)
        return root;

    // Step 2: Search in left and right subtrees
    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    // Step 3: Process results
    if (left && right) return root;   // P and Q found in different subtrees
    if (left) return left;           // Both in left subtree
    if (right) return right;         // Both in right subtree

    return nullptr;                  // None found
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Example Tree:
        
                1
               / \
              2   3
             / \   \
            4   5   6
                 \
                  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    int p = 4, q = 7;
    Node* lca = LCA(root, p, q);

    if (lca)
        cout << "LCA of " << p << " and " << q << " is: " << lca->data << endl;
    else
        cout << "LCA does not exist in the tree." << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited at most once.

Space Complexity: O(H)
- Recursive stack stores up to H nodes (height of tree).
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
================================================================================
*/
