#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform a **zig-zag (spiral) traversal** on a binary tree.

Definition:
- Traverse the binary tree level by level.
- Alternate the direction at each level:
  - Level 1: left to right
  - Level 2: right to left
  - Level 3: left to right
  - and so on…

Example Tree:

        1
       / \
      2   3
     / \   \
    4   5   6

Expected Output: 1 3 2 4 5 6
- Level 1: 1 (left to right)
- Level 2: 3 2 (right to left)
- Level 3: 4 5 6 (left to right)

================================================================================
Intuition / Approach:
================================================================================
Iterative Approach using Queue:
1. Initialize a queue and push root node.
2. Use a flag variable to track direction:
   - false (0) = left to right
   - true (1) = right to left
3. Loop while queue is not empty:
   a) Determine current level size
   b) Initialize temporary vector for current level
   c) For each node in the level:
      - Pop node from queue
      - Add children to queue (left then right)
      - Insert node's value into temporary vector:
         * left to right: push_back
         * right to left: insert at beginning
   d) Append temporary vector to result
   e) Flip flag for next level
4. Return result

Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(N)
- Queue may store all nodes at widest level
- Result stores all N node values

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
// Function to Perform Zig-Zag Traversal
// ---------------------------
vector<int> zigZagTraversal(Node* root) {
    if (!root) return {};

    vector<int> result;
    queue<Node*> q;
    q.push(root);
    bool rightToLeft = false;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();

            // Determine index based on direction
            int index = rightToLeft ? size - i - 1 : i;
            level[index] = node->data;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        rightToLeft = !rightToLeft; // flip direction
        result.insert(result.end(), level.begin(), level.end());
    }

    return result;
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
             / \   \
            4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> traversal = zigZagTraversal(root);

    cout << "Zig-Zag Traversal: ";
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
- Each node is visited once.

Space Complexity: O(N)
- Queue may hold all nodes at widest level
- Result stores all N node values

================================================================================
*/
