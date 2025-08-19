#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Definition of a Node in Binary Tree
// ---------------------------
struct Node {
    int data;       // Stores the value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to quickly create a new node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------------------------
// Postorder Traversal Function (Recursive)
// Rule: LEFT -> RIGHT -> ROOT
// ---------------------------
void postorder(Node* root) {
    // Base Case: If current node is NULL, stop recursion
    if (root == NULL) return;

    // Step 1: Traverse the left subtree first
    postorder(root->left);

    // Step 2: Traverse the right subtree
    postorder(root->right);

    // Step 3: Process (print) the root node
    cout << root->data << " ";
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

    // Creating Nodes
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

    // Print postorder traversal
    cout << "Postorder Traversal of Tree: ";
    postorder(root);

    return 0;
}
