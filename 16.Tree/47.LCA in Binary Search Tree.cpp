// Lowest Common Ancestor (LCA) in a Binary Search Tree (BST)
// ----------------------------------------------------------
// Problem: Given the root of a BST and two nodes p and q, find their Lowest Common Ancestor (LCA).
// The LCA of two nodes is the lowest node in the tree that has both p and q as descendants.
// In a BST, we can leverage the sorted property to find LCA efficiently.

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
// Helper Function: Find LCA
// ---------------------------
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root) return nullptr;

    // If both p and q are smaller → go left
    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // If both p and q are greater → go right
    if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Else → one node is on left, the other on right (or root is p/q)
    return root;
}
// Time Complexity: O(H), where H = height of BST
//   -> O(log N) for balanced BST, O(N) for skewed BST
// Space Complexity: O(H) due to recursion stack
//   -> Can be optimized to O(1) using iterative approach

// ---------------------------
// Iterative Version (O(1) Space)
// ---------------------------
Node* lowestCommonAncestorIterative(Node* root, Node* p, Node* q) {
    while (root) {
        if (p->data < root->data && q->data < root->data) {
            root = root->left;
        } else if (p->data > root->data && q->data > root->data) {
            root = root->right;
        } else {
            return root; // Split point or root is p/q
        }
    }
    return nullptr;
}

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
    // Construct BST
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(9);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    Node* p = root->left->right->left;   // Node 5
    Node* q = root->left->right->right;  // Node 9

    Node* lca = lowestCommonAncestor(root, p, q);
    cout << "Recursive LCA of " << p->data << " and " << q->data << ": " << lca->data << endl;

    Node* lcaIter = lowestCommonAncestorIterative(root, p, q);
    cout << "Iterative LCA of " << p->data << " and " << q->data << ": " << lcaIter->data << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- LCA Definition:
  -> Lowest node with both p and q as descendants.
  -> First intersection point of paths from p and q to root.
- BST Property helps optimize:
  -> If both < root → LCA lies in left subtree.
  -> If both > root → LCA lies in right subtree.
  -> Else → root is the split point → LCA.
- Time Complexity:
  -> O(H), where H = tree height.
  -> Balanced BST: O(log N), Skewed BST: O(N).
- Space Complexity:
  -> Recursive: O(H).
  -> Iterative: O(1).
================================================================================
*/
