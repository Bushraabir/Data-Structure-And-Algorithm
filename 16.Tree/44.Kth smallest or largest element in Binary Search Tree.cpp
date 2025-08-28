// K-th Smallest and K-th Largest Element in a Binary Search Tree (BST)
// -------------------------------------------------------------------
// Problem: Find the K-th smallest or K-th largest element in a BST.
// Inorder traversal of a BST produces elements in sorted order.
// By leveraging this property, we can efficiently solve the problem.

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
// Helper Function: Count Nodes
// ---------------------------
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ---------------------------
// Helper Function: K-th Smallest (Inorder Traversal with Counter)
// ---------------------------
void kthSmallestUtil(Node* root, int& k, int& ans) {
    if (!root) return;

    kthSmallestUtil(root->left, k, ans);

    k--; // Visit current node
    if (k == 0) {
        ans = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, ans);
}

int kthSmallest(Node* root, int k) {
    int ans = -1;
    kthSmallestUtil(root, k, ans);
    return ans;
}
// Time Complexity: O(N) in worst case
// Space Complexity: O(h) recursion stack

// ---------------------------
// Helper Function: K-th Largest
// ---------------------------
int kthLargest(Node* root, int k) {
    int n = countNodes(root);        // Total number of nodes
    int kthSmall = n - k + 1;        // Convert to (N-K+1)-th smallest
    return kthSmallest(root, kthSmall);
}
// Time Complexity: O(N) (2 traversals: one for count, one for kth)
// Space Complexity: O(h) recursion stack

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
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int k1 = 3;
    cout << k1 << "-th Smallest Element: " << kthSmallest(root, k1) << endl;

    int k2 = 2;
    cout << k2 << "-th Largest Element: " << kthLargest(root, k2) << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Inorder traversal of BST gives sorted order of elements.
- K-th Smallest:
  -> Use inorder traversal with counter.
  -> Stop when counter == k.
- K-th Largest:
  -> Convert to (N-K+1)-th smallest.
  -> Requires total node count.
- Time Complexity:
  -> O(N) in worst case (skewed BST).
  -> O(log N) in balanced BST for smaller K.
- Space Complexity:
  -> O(h) due to recursion stack (h = height of BST).
================================================================================
*/
