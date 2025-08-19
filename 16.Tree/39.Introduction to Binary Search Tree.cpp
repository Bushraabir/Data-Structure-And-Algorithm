// Flatten Binary Tree to Linked List
// ----------------------------------
// Problem: Rearrange a binary tree into a flattened linked list following 
// preorder traversal (Root → Left → Right). Must use the existing nodes; 
// no new nodes are created. All left pointers should become null.

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
// 1. Recursive Approach (Reverse Postorder Traversal)
// ---------------------------
Node* prevNode = nullptr;

void flattenRecursive(Node* root) {
    if (!root) return;

    // Process right subtree first
    flattenRecursive(root->right);
    // Process left subtree
    flattenRecursive(root->left);

    // Re-link pointers
    root->right = prevNode;
    root->left = nullptr;
    prevNode = root;
}
// Time Complexity: O(N)
// Space Complexity: O(N) recursion stack

// ---------------------------
// 2. Iterative Approach Using Stack
// ---------------------------
void flattenIterative(Node* root) {
    if (!root) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);

        if (!st.empty()) curr->right = st.top();
        curr->left = nullptr;
    }
}
// Time Complexity: O(N)
// Space Complexity: O(N) for the stack

// ---------------------------
// 3. Morris Traversal Approach (O(1) Space)
// ---------------------------
void flattenMorris(Node* root) {
    Node* curr = root;

    while (curr) {
        if (curr->left) {
            // Find the rightmost node in left subtree
            Node* prev = curr->left;
            while (prev->right) prev = prev->right;

            // Connect rightmost node to current right subtree
            prev->right = curr->right;

            // Move left subtree to right and nullify left
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}
// Time Complexity: O(N)
// Space Complexity: O(1) auxiliary

// ---------------------------
// Utility: Print Flattened Linked List
// ---------------------------
void printFlattened(Node* root) {
    while (root) {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    cout << "Flatten using Recursive Approach: ";
    flattenRecursive(root);
    printFlattened(root);

    // Reset tree for iterative example (recreate nodes)
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    cout << "Flatten using Iterative Stack Approach: ";
    flattenIterative(root);
    printFlattened(root);

    // Reset tree for Morris example
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    cout << "Flatten using Morris Traversal Approach: ";
    flattenMorris(root);
    printFlattened(root);

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Preorder traversal dictates the order of the flattened list.
- Recursive and iterative stack approaches use O(N) space.
- Morris approach achieves O(1) auxiliary space.
- All methods modify the tree in place; no new nodes are created.
================================================================================
*/
