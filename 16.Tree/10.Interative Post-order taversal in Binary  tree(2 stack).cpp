#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform an **Iterative Postorder Traversal** of a binary tree using **two stacks**.  
In **Postorder Traversal**, nodes are visited in the order:
    Left Subtree -> Right Subtree -> Root

Instead of recursion, use two stacks to simulate the traversal order.

Example Tree:

            1
           / \
          2   3
         / \ / \
        4  5 6  7

Expected Postorder Output: 4 5 2 6 7 3 1

================================================================================
Intuition / Approach:
================================================================================
1. Use two stacks: s1 for processing nodes, s2 for storing nodes in reverse postorder.
2. Steps:
    a) Push root to s1.
    b) While s1 is not empty:
        - Pop top node from s1 (call it curr) and push it to s2.
        - Push left child of curr to s1 if it exists.
        - Push right child of curr to s1 if it exists.
       (Pushing left first ensures right is processed before left in s2.)
    c) After s1 is empty, pop nodes from s2 one by one to get postorder sequence.
3. This effectively produces Left-Right-Root order iteratively.

Time Complexity: O(N)
- Each node is pushed and popped from both stacks exactly once.

Space Complexity: O(N)
- Two stacks are used; in worst case, they may store all nodes.

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
        left = right = NULL;
    }
};

// ---------------------------
// Iterative Postorder Traversal Using 2 Stacks
// LEFT -> RIGHT -> ROOT
// ---------------------------
void iterativePostorder(Node* root) {
    if (!root) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top(); s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
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
         / \ / \
        4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Iterative Postorder Traversal (2 Stacks) of Tree: ";
    iterativePostorder(root);
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is pushed and popped from both stacks exactly once.
- Total operations = O(N).

Space Complexity: O(N)
- Two stacks are used, each can hold up to N nodes in worst case.
- Total auxiliary space = O(2N) → O(N).

================================================================================
*/
