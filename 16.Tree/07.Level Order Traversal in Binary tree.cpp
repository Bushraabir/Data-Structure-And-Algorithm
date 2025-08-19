#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Definition of a Node in Binary Tree
// ---------------------------
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to quickly create a node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------------------------
// Level Order Traversal Function (BFS)
// Uses a queue to traverse nodes level by level
// ---------------------------
vector<vector<int>> levelOrderTraversal(Node* root) {
    vector<vector<int>> ans;  // Stores the result level by level

    if (root == NULL) return ans; // If tree is empty, return empty vector

    queue<Node*> q;       // Queue to store nodes to be processed
    q.push(root);         // Start with the root node

    while (!q.empty()) {  // Process until all nodes are traversed
        int size = q.size();       // Number of nodes at current level
        vector<int> level;         // Stores nodes of the current level

        // Process all nodes at this level
        for (int i = 0; i < size; i++) {
            Node* node = q.front();  // Get the front node from queue
            q.pop();                 // Remove it from queue

            level.push_back(node->data);  // Add node's data to current level

            // If left child exists, enqueue it
            if (node->left != NULL) q.push(node->left);

            // If right child exists, enqueue it
            if (node->right != NULL) q.push(node->right);
        }

        // Add the current level to the final answer
        ans.push_back(level);
    }

    return ans;  // Return the level order traversal
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
