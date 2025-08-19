#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **bottom view** of a binary tree.

Definition:
- The bottom view contains nodes visible when the tree is viewed from the bottom.
- For each vertical line (line number), the **last node encountered** in level order traversal is included.
- Nodes are listed from leftmost line to rightmost line.

Example Tree:

            1
           / \
          2   3
         / \   \
        4   5   7
             \
              6

Expected Output: 4 8 6 9 7
- Line -2: 4
- Line -1: 8
- Line 0: 6
- Line 1: 9
- Line 2: 7

================================================================================
Intuition / Approach:
================================================================================
Level Order Traversal (BFS) with Horizontal Distances:
1. Assign line numbers (horizontal distance) to each node:
   - Root: line = 0
   - Left child: line - 1
   - Right child: line + 1
2. Use a map to store the last node at each line:
   - map<int, int> bottomNodes;  // line → node value
   - Overwrite value for each line whenever a node is encountered
3. Use a queue for BFS:
   - queue<pair<Node*, int>> q;  // Node + line
4. BFS Loop:
   a) Dequeue node with its line
   b) Update map with current node's value
   c) Enqueue left child with line-1
   d) Enqueue right child with line+1
5. Construct result vector by iterating map in order of line keys
6. Return result

Time Complexity: O(N)
- Each node is visited once
- Map insertion/update takes O(log N) per node in worst case

Space Complexity: O(N)
- Queue may store up to O(W) nodes (max width)
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
// Bottom View Function
// ---------------------------
vector<int> bottomView(Node* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> bottomNodes;  // line → node value
    queue<pair<Node*, int>> q;  // Node + line
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, line] = q.front(); q.pop();

        // Always update/overwrite map with current node
        bottomNodes[line] = curr->data;

        if (curr->left) q.push({curr->left, line - 1});
        if (curr->right) q.push({curr->right, line + 1});
    }

    // Extract bottom view nodes in left-to-right order
    for (auto& [line, val] : bottomNodes) {
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

    vector<int> traversal = bottomView(root);

    cout << "Bottom View: ";
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
- Map insertion/update takes O(log N) per node in worst case

Space Complexity: O(N)
- Queue may store up to O(W) nodes (max width)
- Map stores up to O(N) nodes
- Total auxiliary space: O(N)

================================================================================
*/
