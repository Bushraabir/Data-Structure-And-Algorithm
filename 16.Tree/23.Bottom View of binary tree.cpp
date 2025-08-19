#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **bottom view** of a binary tree.

Definition:
- The bottom view of a binary tree is the set of nodes visible when looking 
  at the tree from the bottom.

Example Tree:

            1
           / \
          2   3
         / \   \
        4   5   7
             \
              6

Bottom View Output: 4, 8, 6, 9, 7

================================================================================
Intuition / Approach:
================================================================================
Level Order Traversal (BFS) with Line (Horizontal Distance):

1. Assign a horizontal distance (line number) to each node:
   - Root: line 0
   - Left child: line - 1
   - Right child: line + 1

2. Use a map<int, int> to store the latest node encountered at each line:
   - Each time a node is encountered during BFS, update the map with its value.
   - This ensures the last node at each line (i.e., bottommost) is stored.

3. Use a queue<pair<Node*, int>> for BFS:
   - pair contains node pointer and its line number.
   - Enqueue root with line 0.
   - For each node:
     a) Update map[line] = node->data
     b) Enqueue left child with line - 1
     c) Enqueue right child with line + 1

4. After BFS completes, traverse the map in order of keys:
   - Collect values to get the bottom view from left to right.

Time Complexity: O(N)
- Each node is visited exactly once.
- Map operations take O(log K) where K = number of distinct lines ≤ N

Space Complexity: O(N)
- Queue can store up to O(W) nodes (W = max width)
- Map can store up to O(N) nodes

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
// Function to Find Bottom View
// ---------------------------
vector<int> bottomView(Node* root) {
    if (!root) return {};

    map<int, int> lineMap;               // line number -> bottommost node
    queue<pair<Node*, int>> q;           // BFS queue

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, line] = q.front();
        q.pop();

        // Overwrite value at this line with current node
        lineMap[line] = node->data;

        if (node->left) q.push({node->left, line - 1});
        if (node->right) q.push({node->right, line + 1});
    }

    vector<int> result;
    for (auto& [line, val] : lineMap) {
        result.push_back(val);
    }
    return result;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Example Tree:

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
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);

    vector<int> bottom = bottomView(root);

    cout << "Bottom View: ";
    for (int val : bottom) cout << val << " ";
    cout << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once during BFS.
- Map insertion/update takes O(log K), K ≤ N, overall O(N log N) in strict sense.

Space Complexity: O(N)
- Queue can hold up to O(W) nodes (max width)
- Map stores up to O(N) nodes
- Overall: O(N)
================================================================================
*/
