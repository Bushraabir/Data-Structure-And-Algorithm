// Inorder Successor in a BST
// ----------------------------------------------------------
// Problem: Given a node (target) in a BST, find its inorder successor.
// Inorder Successor = Next node in the inorder (sorted) traversal.
// If no successor exists (target is the largest), return NULL.
//
// Example:
// Inorder traversal: 1 2 3 4 5 6 7 8 9 10
// Successor of 8 = 9
// Successor of 10 = NULL
//
// ----------------------------------------------------------
// Approach: Iterative Traversal with Successor Variable (Efficient O(H))
// ----------------------------------------------------------
// - Initialize successor = NULL.
// - Start from root, compare current node with target value:
//   -> If current->data <= target->data:
//        Move right (successor must be larger).
//   -> Else (current->data > target->data):
//        Current node is a possible successor.
//        Save it and move left (try to find smaller but > target).
// - Continue until current == NULL.
// - The saved successor is the inorder successor (or NULL if none).

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
// Insert into BST (utility for testing)
// ---------------------------
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// ---------------------------
// Function to Find Inorder Successor
// ---------------------------
Node* inorderSuccessor(Node* root, Node* p) {
    Node* successor = nullptr;
    while (root) {
        if (root->data <= p->data) {
            // successor must be larger, so go right
            root = root->right;
        } else {
            // possible successor, save it and go left
            successor = root;
            root = root->left;
        }
    }
    return successor;
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
    Node* root = nullptr;
    vector<int> values = {5, 3, 7, 2, 4, 6, 8, 9};
    for (int v : values) root = insert(root, v);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    Node* target = root->left->right; // Node with value 4
    Node* succ = inorderSuccessor(root, target);

    if (succ) cout << "Inorder Successor of " << target->data << " is: " << succ->data << endl;
    else cout << "Inorder Successor does not exist for " << target->data << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- BST Property:
  -> Left < Node < Right for every node.
  -> Inorder traversal gives nodes in sorted order.
- Successor Definition:
  -> Smallest node strictly greater than the given node.
- Algorithm (Efficient Iterative O(H)):
  -> Traverse from root.
  -> If current <= target → go right (successor must be bigger).
  -> If current > target → save current as successor, then go left.
  -> End when root == NULL.
- Time Complexity:
  -> O(H), where H = height of tree.
  -> Balanced BST: O(log N), Skewed BST: O(N).
- Space Complexity:
  -> O(1), no extra storage apart from variables.
- Edge Cases:
  -> Largest node → successor = NULL.
  -> Node with right subtree → successor is leftmost node of right subtree
     (this case is naturally handled by traversal).
================================================================================
*/
