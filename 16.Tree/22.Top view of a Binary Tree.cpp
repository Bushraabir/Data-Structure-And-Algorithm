#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **top view** of a binary tree.

Definition:
- The top view contains nodes visible when the tree is viewed from above.
- For each vertical line (line number), only the first node encountered from top to bottom is included.
- Nodes are listed from leftmost line to rightmost line.

Example Tree:

            1
           / \
          2   3
         / \   \
        4   5   7
             \
              6

Expected Output: 4 2 1 3 7
- Line -2: 4
- Line -1: 2
- Line 0: 1
- Line 1: 3
- Line 2: 7

================================================================================
Intuition / Approach:
================================================================================
Level Order Traversal (BFS) with Horizontal Distances:
1. Assign line numbers (horizontal distance) to each node:
   - Root: line = 0
   - Left child: line - 1
   - Right child: line + 1
2. Use a map to store first node at each line:
   - map<int, int> topNodes;  // line → node value
   - Ensures keys (lines) are sorted (left to right)
3. Use a queue for BFS:
   - queue<pair<Node*, int>> q;  // Node + line
4. BFS Loop:
   a) Dequeue node with its line
   b) If line not in map, insert node's value
   c) Enqueue left child with line-1
   d) Enqueue right child with line+1
5. Construct result vector by iterating map in order of line keys
6. Return result

Time Complexity: O(N)
- Each node is visited once
- Map insertions take O(log N) but each node is processed only once

Space Complexity: O(N)
- Queue stores up to O(W) nodes (W = max width)
- Map stores up to O(N) entries

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
// Top View Function
// ---------------------------
vector<int> topView(Node* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> topNodes;  // line → node value
    queue<pair<Node*, int>> q;  // Node + line
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, line] = q.front(); q.pop();

        // Insert only if this line is encountered for the first time
        if (topNodes.find(line) == topNodes.end()) {
            topNodes[line] = curr->data;
        }

        if (curr->left) q.push({curr->left, line - 1});
        if (curr->right) q.push({curr->right, line + 1});
    }

    // Extract top view nodes in left-to-right order
    for (auto& [line, val] : topNodes) {
        result.push_back(val);
    }

    return result;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Binary Tree:

                1
               / \
              2   3
             / \   \
            4   5   7
                 \
                  6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->right->right = new Node(6);

    vector<int> traversal = topView(root);

    cout << "Top View: ";
    for (int val : traversal)
        cout << val << " ";
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node visited once
- Map insertions take O(log N) per node in worst case

Space Complexity: O(N)
- Queue may store up to O(W) nodes (max width)
- Map stores up to O(N) nodes
- Total auxiliary space: O(N)

================================================================================
*/
