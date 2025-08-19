#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform a **Level Order Traversal** (Breadth-First Search) of a binary tree.  
In **Level Order Traversal**, nodes are visited **level by level** from top to bottom,
and within each level, nodes are visited from **left to right**.

Given a binary tree, print or return the nodes level-wise using an **iterative approach** 
with a **queue**.

Example Tree:
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7

Expected Level Order Output:
[
    [1],
    [2, 3],
    [4, 5, 6, 7]
]

================================================================================
Intuition / Approach:
================================================================================
1. Level order traversal is BFS on a binary tree.
2. Use a **queue** to store nodes to be processed (FIFO).
3. Start by pushing the **root node** into the queue.
4. While the queue is not empty:
    a) Determine the number of nodes at the current level (`size = q.size()`).
    b) Process each node of the current level:
        - Pop the node from the front of the queue.
        - Add its value to a temporary list for this level.
        - If left child exists, enqueue it.
        - If right child exists, enqueue it.
    c) Add the temporary level list to the final answer.
5. Continue until all levels are processed.
6. Return the final list of levels.

Time Complexity: O(N), as each node is visited exactly once.
Space Complexity: O(N), for the queue in the worst case (e.g., last level of a full tree).
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
// Level Order Traversal Function (BFS)
// ---------------------------
vector<vector<int>> levelOrderTraversal(Node* root) {
    vector<vector<int>> ans;  // Stores nodes level by level

    if (root == NULL) return ans; // If tree is empty, return empty vector

    queue<Node*> q;       // Queue to store nodes to be processed
    q.push(root);         // Start with root node

    while (!q.empty()) {
        int size = q.size();       // Number of nodes at current level
        vector<int> level;         // Stores nodes of the current level

        for (int i = 0; i < size; i++) {
            Node* node = q.front();  // Get the front node
            q.pop();                 // Remove it from queue

            level.push_back(node->data);  // Add node's data to current level

            if (node->left != NULL) q.push(node->left);    // Enqueue left child
            if (node->right != NULL) q.push(node->right);  // Enqueue right child
        }

        ans.push_back(level);  // Add the current level to final answer
    }

    return ans;  // Return complete level order traversal
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

        Level Order Traversal Output:
        [
            [1],
            [2, 3],
            [4, 5, 6, 7]
        ]
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = levelOrderTraversal(root);

    cout << "Level Order Traversal:\n";
    for (auto level : result) {
        for (auto val : level) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
