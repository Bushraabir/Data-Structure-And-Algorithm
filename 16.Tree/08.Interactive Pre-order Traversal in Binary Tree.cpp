#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform an **Iterative Preorder Traversal** of a binary tree.  
In **Preorder Traversal**, the order of visiting nodes is:
    Root -> Left Subtree -> Right Subtree

Given a binary tree, print or return the nodes in preorder using an **iterative approach** 
(without recursion) using a stack.

Example Tree:
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7

Expected Iterative Preorder Output: 1 2 4 5 3 6 7

================================================================================
Intuition / Approach:
================================================================================
1. Preorder is "Root -> Left -> Right".
2. Use a **stack** to simulate recursion (LIFO).
3. Push the **root node first** into the stack.
4. While stack is not empty:
    a) Pop the top node, process it (add to result/output).  
    b) Push **right child first**, then **left child**.  
       - This ensures the **left child is processed before the right child**, because stack is LIFO.
5. Continue until the stack is empty.
6. The result contains the preorder traversal sequence.

Time Complexity: O(N), as each node is pushed and popped exactly once.
Space Complexity: O(H), where H is the height of the tree (stack usage).
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
// Iterative Preorder Traversal Function
// Root -> Left -> Right
// ---------------------------
vector<int> iterativePreorder(Node* root) {
    vector<int> result;       // Stores the preorder traversal sequence

    if (root == NULL) return result;  // Empty tree check

    stack<Node*> st;          // Stack to help traverse the tree iteratively
    st.push(root);            // Start with root node

    while (!st.empty()) {
        Node* curr = st.top(); // Get the top node from the stack
        st.pop();              // Remove it from stack

        result.push_back(curr->data);  // Process root: add node value to result

        // Push right child first so that left child is processed first
        if (curr->right != NULL) st.push(curr->right);

        // Push left child
        if (curr->left != NULL) st.push(curr->left);
    }

    return result;  // Complete preorder traversal
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
             4   5 6   7

        Iterative Preorder Traversal Output:
        1 2 4 5 3 6 7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = iterativePreorder(root);

    cout << "Iterative Preorder Traversal:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
